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
    EFFECT = BURNING;
}

void PokeFire::attackTo(Pokemon *target, Arena currentArena) {
    applyEffect(EFFECT, target);
}

void PokeFire::levelUp() {
    level ++;
    getLevelBonus();
}

void PokeFire::setBurning(bool burning){
    this->burning = false;
}

void PokeFire::setEffDamage() {
    if(drowning){
        CUR_EFF_DAM = DROWN_DAMAGE * 2;
        isDoubled = true;
    }
    else if(electrified){
        CUR_EFF_DAM = ELECTRIFY_DAMAGE;
        isDoubled = false;
    }
    else if(rooted){
        CUR_EFF_DAM = ROOT_DAMAGE;
        isDoubled = false;
    }
}

void PokeFire::Info() {
    std::cout << "[" << name << ", " << pokemonID << ", FIRE]" << std::endl;
}

void PokeFire::Reset() {
    CUR_EFF_DAM = 0;
    CUR_ATT_DAM = 0;
    burning = false;
    drowning = false;
    electrified = false;
    rooted = false;
    dead = false;
    isDoubled = false;

    HP = 600;
    ATK = 60;
    MAG_DEF = 20;
    PHY_DEF = 10;

    getLevelBonus();
}

void PokeFire::getLevelBonus() {
    HP += 60 * level;
    ATK += 6 * level;
    MAG_DEF += 2 * level;
    PHY_DEF += 1 * level;
}

void PokeFire::setArenaEff(Arena arena) {
    switch(arena)
    {
        case MAGMA:
            HP += 100; ATK += 10; arenaBuff = 1;
            break;
        case OCEAN:
            HP -= 100; ATK -= 10; arenaBuff = -1;
            break;
        case SKY:
            HP -= 100; ATK -= 10; arenaBuff = -1;
            break;
        case STADIUM:
            arenaBuff = 0;
    }
}
