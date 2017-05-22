//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include "Pokemon.h"
#include "PokeGrass.h"

PokeGrass::PokeGrass(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 800;
    ATK = 40;
    MAG_DEF = 0;
    PHY_DEF = 30;
}

void PokeGrass::attackTo(Pokemon *target, Arena currentArena) {
    if(!target->isRooted()){
        target->setRooted(true);
        target->setDamage();
    }
}

void PokeGrass::levelUp() {
    HP += 80;
    ATK += 4;
    MAG_DEF += 0;
    PHY_DEF += 3;
}

void PokeGrass::setRooted(bool rooted) {
    this->rooted = false;
}

void PokeGrass::setDamage() {
    if(burning)
        CUR_DAM = BURN_DAMAGE * 2;
    else if(drowning)
        CUR_DAM = DROWN_DAMAGE;
    else if(electrified)
        CUR_DAM = ELECTRIFY_DAMAGE;
}


