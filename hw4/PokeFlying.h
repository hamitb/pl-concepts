#ifndef POKEFLYING_H
#define POKEFLYING_H

#include "Pokemon.h"

class PokeFlying : public Pokemon
{
public:
	// Add your public methods/attributes here.
    PokeFlying(int pokemonID, const std::string& name);
    void attackTo(Pokemon* target, Arena currentArena);
    void levelUp();
    void setElectrified(bool electrified);
    void setDrowning(bool drowning);
    void setBurning(bool burning);
    void setRooted(bool rooted);
    void Info();
    void Reset();
    void setArenaEff(Arena arena);
    void setEffected(bool effected);
protected:
	// Add your protected methods/attributes here.
    virtual void getLevelBonus();
private:
	// Add your private methods/attributes here.
	
};

#endif