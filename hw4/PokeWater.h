#ifndef POKEWATER_H
#define POKEWATER_H

#include "Pokemon.h"

class PokeWater : public Pokemon
{
public:
	// Add your public methods/attributes here.
    PokeWater(int pokemonID, const std::string& name);
    void attackTo(Pokemon* target, Arena currentArena);
    void levelUp();
    void setDrowning(bool drowning);
    void Reset();
    void setArenaEff(Arena arena);
protected:
	// Add your protected methods/attributes here.
    void setEffDamage(Effect effect);
    void updateEffDamage();
    void getLevelBonus();
    void resetLevelBonus();
private:
	// Add your private methods/attributes here.
	
};

#endif