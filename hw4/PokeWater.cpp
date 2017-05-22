//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include "Pokemon.h"
#include "PokeWater.h"

PokeWater::PokeWater(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 700;
    ATK = 50;
    MAG_DEF = 10;
    PHY_DEF = 20;
}

void PokeWater::attackTo(Pokemon *target, Arena currentArena) {
    if(!target->isDrowning()){
        target->setDrowning(true);
        target->setDamage();
    }
}

void PokeWater::levelUp() {
    HP += 70;
    ATK += 5;
    MAG_DEF += 1;
    PHY_DEF += 2;
}

void PokeWater::setDrowning(bool drowning){
    this->drowning = false;
}

void PokeWater::setDamage() {
    if(electrified)
        CUR_DAM = ELECTRIFY_DAMAGE * 2;
    else if(burning)
        CUR_DAM = BURN_DAMAGE;
    else if(rooted)
        CUR_DAM = ROOT_DAMAGE;
}

