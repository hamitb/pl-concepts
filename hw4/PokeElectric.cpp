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

void PokeElectric::setEffDamage(Effect effect) {
    switch(effect){
        case ROOTED:
            CUR_RTD_DAM = std::max(0, ROOT_DAMAGE * 2 - MAG_DEF);
            effectIntensity_DRW = "!!!!";
            break;
        case BURNING:
            CUR_BRN_DAM = std::max(0, BURN_DAMAGE - MAG_DEF);
            effectIntensity_ELC = "!!";
            break;
        case DROWNING:
            CUR_DRW_DAM = std::max(0, DROWN_DAMAGE - MAG_DEF);
            effectIntensity_RTD = "!!";
            break;
    }
}

void PokeElectric::Info() {
    std::cout << "[" << name << ", " << pokemonID << ", ELECTRIC]" << std::endl;
}

void PokeElectric::Reset() {
    CUR_BRN_DAM = 0;
    CUR_DRW_DAM = 0;
    CUR_ELC_DAM = 0;
    CUR_RTD_DAM = 0;
    CUR_ATT_DAM = 0;
    burning = false;
    drowning = false;
    electrified = false;
    rooted = false;
    dead = false;
    effected = false;
    arenaEffected = false;
    effectIntensity_BRN = "";
    effectIntensity_DRW = "";
    effectIntensity_ELC = "";
    effectIntensity_RTD = "";


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
    if(!isArenaEffected()) {
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
            default:
                arenaBuff = '/';
        }

        arenaEffected = true;
    }
}

void PokeElectric::updateEffDamage() {
    if (isRooted()){
        CUR_RTD_DAM = std::max(0, ROOT_DAMAGE * 2 - MAG_DEF);
        effectIntensity_DRW = "!!!!";
    }
    if(isBurning()){
        CUR_BRN_DAM = std::max(0, BURN_DAMAGE - MAG_DEF);
        effectIntensity_ELC = "!!";
    }
    if(isRooted()) {
        CUR_DRW_DAM = std::max(0, DROWN_DAMAGE - MAG_DEF);
        effectIntensity_RTD = "!!";
    }
}
