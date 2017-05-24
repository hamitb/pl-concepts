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

void PokeWater::setEffDamage(Effect effect) {
    switch(effect){
        case ELECTRIFIED:
            CUR_ELC_DAM = std::max(0, ELECTRIFY_DAMAGE * 2 - MAG_DEF);
            effectIntensity_ELC = "!!!!";
            setEffected(true);
            break;
        case BURNING:
            CUR_BRN_DAM = std::max(0, BURN_DAMAGE - MAG_DEF);
            effectIntensity_BRN = "!!";
            setEffected(true);
            break;
        case ROOTED:
            CUR_RTD_DAM = std::max(0, ROOT_DAMAGE - MAG_DEF);
            effectIntensity_RTD = "!!";
            setEffected(true);
            break;
    }
}

void PokeWater::Reset() {
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


    HP = 700;
    ATK = 50;
    MAG_DEF = 10;
    PHY_DEF = 20;

    resetLevelBonus();
}

void PokeWater::resetLevelBonus() {
    HP += 70 * level;
    ATK += 5 * level;
    MAG_DEF += 1 * level;
    PHY_DEF += 2 * level;
}

void PokeWater::getLevelBonus() {
    HP += 70;
    ATK += 5;
    MAG_DEF += 1;
    PHY_DEF += 2;
}

void PokeWater::setArenaEff(Arena arena) {
    if(!isArenaEffected()) {
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

}

void PokeWater::updateEffDamage() {
    if (isElectrified()){
        CUR_ELC_DAM = std::max(0, ELECTRIFY_DAMAGE * 2 - MAG_DEF);
        effectIntensity_ELC = "!!!!";
    }
    if(isBurning()){
        CUR_BRN_DAM = std::max(0, BURN_DAMAGE - MAG_DEF);
        effectIntensity_BRN = "!!";
    }
    if(isRooted()) {
        CUR_RTD_DAM = std::max(0, ROOT_DAMAGE - MAG_DEF);
        effectIntensity_RTD = "!!";
    }
}

