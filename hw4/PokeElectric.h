#ifndef POKEELECTRIC_H
#define POKEELECTRIC_H

#include "Pokemon.h"

class PokeElectric : public Pokemon
{
public:
	// Add your public methods/attributes here.
    PokeElectric(int pokemonID, const std::string& name);
    void attackTo(Pokemon* target, Arena currentArena);
    void levelUp();
    void setElectrified(bool electrified);
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