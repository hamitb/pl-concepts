//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <algorithm>
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
    if(!target->isEfected())
        applyEffect(EFFECT, target);
    int damage = calculateDamage(target);
    target->setAttDamage(damage);
    target->getAttDamage();
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
        CUR_EFF_DAM = std::max(0, DROWN_DAMAGE * 2 - MAG_DEF);
        effectIntensity = "!!!!";
    }
    else if(electrified){
        CUR_EFF_DAM = std::max(0, ELECTRIFY_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
    }
    else if(rooted){
        CUR_EFF_DAM = std::max(0, ROOT_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
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
    effected = false;
    arenaEffected = false;
    effectIntensity = "";
    effectStatus = "";

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
            HP += 100; ATK += 10; arenaBuff = '+';
            break;
        case OCEAN:
            HP -= 100; ATK -= 10; arenaBuff = '-';
            break;
        case SKY:
            HP -= 100; ATK -= 10; arenaBuff = '-';
            break;
        default:
            arenaBuff = '/';
    }

    arenaEffected = true;
}
