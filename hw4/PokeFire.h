#ifndef POKEFIRE_H
#define POKEFIRE_H

#include "Pokemon.h"

class PokeFire : public Pokemon
{
public:
	// Add your public methods/attributes here.
    PokeFire(int pokemonID, const std::string& name);
    void attackTo(Pokemon* target, Arena currentArena);
    void levelUp();
    void setBurning(bool burning);
    void Info();
    void Reset();
    void setArenaEff(Arena arena);
protected:
    // Add your protected methods/attributes here.
    void setEffDamage(Effect effect);
    void updateEffDamage();
    virtual void getLevelBonus();

private:
	// Add your private methods/attributes here.
};

#endif