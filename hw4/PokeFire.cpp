//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <iostream>
#include "Pokemon.h"
#include "PokeFire.h"

PokeFire::PokeFire(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 600;
    ATK = 60;
    MAG_DEF = 20;
    PHY_DEF = 10;
}

void PokeFire::attackTo(Pokemon *target, Arena currentArena) {
    if(!target->isBurning()){
        target->setBurning(true);
        target->setDamage();
    }
}

void PokeFire::levelUp() {
    HP += 60;
    ATK += 6;
    MAG_DEF += 2;
    PHY_DEF += 1;
}

void PokeFire::setBurning(bool burning){
    this->burning = false;
}

void PokeFire::setDamage() {
    if(drowning)
        CUR_DAM = DROWN_DAMAGE * 2;
    else if(electrified)
        CUR_DAM = ELECTRIFY_DAMAGE;
    else if(rooted)
        CUR_DAM = ROOT_DAMAGE;
}

void PokeFire::Info() {
    std::cout << "[" << name << ", " << pokemonID << ", FIRE]" << std::endl;
}
