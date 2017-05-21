//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include "Pokemon.h"
#include "PokeElectric.h"

PokeElectric::PokeElectric(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 500;
    ATK = 70;
    MAG_DEF = 30;
    PHY_DEF = 0;
}

void PokeElectric::attackTo(Pokemon *target, Arena currentArena) {
    if(!target->electrified) {
        target->setElectrified(true);
        target->setDamage();
    }
}

void PokeElectric::levelUp() {
    HP += 50;
    ATK += 7;
    MAG_DEF += 3;
    PHY_DEF += 0;
}

void PokeElectric::setElectrified(bool electrified) {
    this->electrified = false;
}

void PokeElectric::setDamage() {
    if(rooted)
        CUR_DAM = ROOT_DAMAGE * 2;
    else if(burning)
        CUR_DAM = BURN_DAMAGE;
    else if(drowning)
        CUR_DAM = DROWN_DAMAGE;
}
