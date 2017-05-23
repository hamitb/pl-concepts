//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <iostream>
#include "Pokemon.h"
#include "PokeWater.h"

PokeWater::PokeWater(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 700;
    ATK = 50;
    MAG_DEF = 10;
    PHY_DEF = 20;
    EFFECT = DROWNING;

}

void PokeWater::attackTo(Pokemon *target, Arena currentArena) {
    if(!target->isEfected())
        applyEffect(EFFECT, target);
    int damage = calculateDamage(target);
    target->setAttDamage(damage);
    target->getAttDamage();
}

void PokeWater::levelUp() {
    level ++;
    getLevelBonus();
}

void PokeWater::setDrowning(bool drowning){
    this->drowning = false;
}

void PokeWater::setEffDamage() {
    if(electrified){
        CUR_EFF_DAM = std::max(0, ELECTRIFY_DAMAGE * 2 - MAG_DEF);

        effectIntensity = "!!!!";
    }
    else if(burning){
        CUR_EFF_DAM = std::max(0, BURN_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
    }
    else if(rooted){
        CUR_EFF_DAM = std::max(0, ROOT_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
    }
}

void PokeWater::Reset() {
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


    HP = 700;
    ATK = 50;
    MAG_DEF = 10;
    PHY_DEF = 20;

    getLevelBonus();
}

void PokeWater::Info() {
    std::cout << "[" << name << ", " << pokemonID << ", WATER]" << std::endl;
}

void PokeWater::getLevelBonus() {
    HP += 70 * level;
    ATK += 5 * level;
    MAG_DEF += 1 * level;
    PHY_DEF += 2 * level;
}

void PokeWater::setArenaEff(Arena arena) {
    switch(arena)
    {
        case OCEAN:
            HP += 100; ATK += 10; arenaBuff = '+';
            break;
        case ELECTRICITY:
            HP -= 100; ATK -= 10; arenaBuff = '-';
            break;
        case FOREST:
            HP -= 100; ATK -= 10; arenaBuff = '-';
            break;
        default:
            arenaBuff = '/';
    }

    arenaEffected = true;
}

