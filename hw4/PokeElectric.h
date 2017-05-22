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
    void setDamage();
    void Info();
protected:
	// Add your protected methods/attributes here.
private:
	// Add your private methods/attributes here.
	
};

#endif