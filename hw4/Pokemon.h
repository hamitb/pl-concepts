#ifndef POKEMON_H
#define POKEMON_H

#include <string>

#include "Enums.h"

class Pokemon
{
public:
	// Public Methods

	Pokemon(int pokemonID, const std::string& name);
	~Pokemon();

	virtual void attackTo(Pokemon* target, Arena currentArena) = 0;	// Purity!
	virtual void levelUp() = 0;		// Purity !

	// Getters

	int getPokemonID() const;
	const std::string& getName() const;

	int getHP() const;
	int getATK() const;
	int getMAG_DEF() const;
	int getPHY_DEF() const;

	bool isBurning() const;
	bool isDrowning() const;
	bool isElectrified() const;
	bool isRooted() const;

	// Setters

	virtual void setBurning(bool burning);
	virtual void setDrowning(bool drowning);
	virtual void setElectrified(bool electrified);
	virtual void setRooted(bool rooted);

	// Own Methods
    virtual void setEffDamage();
    virtual void setEffected(bool effected);
    virtual void Info() = 0;
    virtual void Reset() = 0;
    virtual void setArenaEff(Arena arena) = 0;
    void setAttDamage(int damage);
    char getArenaEff();
    int getAttDamage();
    int getEffDamage();
    bool isEfected();
	bool isArenaEffected();
    void applyEffect(Effect effect, Pokemon* target);
    int calculateDamage(Pokemon *target);
    bool isDead();
	std::string getEffIntensity();
	std::string getEffStatus();
protected:
    virtual void getLevelBonus() = 0;
    void updateDeadStatus();
    int pokemonID; 	// Unique

	std::string name;

	int HP;
	int ATK;
	int MAG_DEF;
	int PHY_DEF;

	bool burning;
	bool drowning;
	bool electrified;
	bool rooted;

	// Own Attributes
	int CUR_EFF_DAM;
    int CUR_ATT_DAM;
    bool dead;
    bool effected;
	bool arenaEffected;
    char arenaBuff;
    int level;
    std::string effectIntensity;
	std::string effectStatus;
    Effect EFFECT;
};

#endif