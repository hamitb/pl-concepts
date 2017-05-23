//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <iostream>
#include "Pokemon.h"
#include "PokeElectric.h"

PokeElectric::PokeElectric(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 500;
    ATK = 70;
    MAG_DEF = 30;
    PHY_DEF = 0;
    EFFECT = ELECTRIFIED;
}

void PokeElectric::attackTo(Pokemon *target, Arena currentArena) {
    if(!target->isEfected())
        applyEffect(EFFECT, target);
    int damage = calculateDamage(target);
    target->setAttDamage(damage);
    target->getAttDamage();
}

void PokeElectric::levelUp() {
    level++;
    getLevelBonus();
}

void PokeElectric::setElectrified(bool electrified) {
    this->electrified = false;
}

void PokeElectric::setEffDamage() {
    if(rooted){
        CUR_EFF_DAM = std::max(0, ROOT_DAMAGE * 2 - MAG_DEF);
        effectIntensity = "!!!!";
    }
    else if(burning){
        CUR_EFF_DAM = std::max(0, BURN_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
    }
    else if(drowning){
        CUR_EFF_DAM = std::max(0, DROWN_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
    }
}

void PokeElectric::Info() {
    std::cout << "[" << name << ", " << pokemonID << ", ELECTRIC]" << std::endl;
}

void PokeElectric::Reset() {
    CUR_EFF_DAM = 0;
    CUR_ATT_DAM = 0;
    burning = false;
    drowning = false;
    electrified = false;
    rooted = false;
    dead = false;
    effectIntensity = "";
    effected = false;
    arenaEffected = false;
    effectStatus = "";


    HP = 500;
    ATK = 70;
    MAG_DEF = 30;
    PHY_DEF = 0;

    getLevelBonus();
}

void PokeElectric::getLevelBonus() {
    HP += 50 * level;
    ATK += 7 * level;
    MAG_DEF += 3 * level;
    PHY_DEF += 0 * level;
}

void PokeElectric::setArenaEff(Arena arena) {
    switch(arena)
    {
        case ELECTRICITY:
            HP += 100; ATK += 10; arenaBuff = '+';
            break;
        case MAGMA:
            HP -= 100; ATK -= 10; arenaBuff = '-';
            break;
        case FOREST:
            HP -= 100; ATK -= 10; arenaBuff = '-';
            break;
        case STADIUM:
            arenaBuff = '/';
    }

    arenaEffected = true;
}
