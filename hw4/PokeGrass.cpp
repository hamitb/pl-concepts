//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <iostream>
#include "Pokemon.h"
#include "PokeGrass.h"

PokeGrass::PokeGrass(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 800;
    ATK = 40;
    MAG_DEF = 0;
    PHY_DEF = 30;
    EFFECT = ROOTED;
}

void PokeGrass::attackTo(Pokemon *target, Arena currentArena) {
    if(!target->isEfected())
        applyEffect(EFFECT, target);
    int damage = calculateDamage(target);
    target->setAttDamage(damage);
    target->getAttDamage();
}

void PokeGrass::levelUp() {
    level ++;
    getLevelBonus();
}

void PokeGrass::setRooted(bool rooted) {
    this->rooted = false;
}

void PokeGrass::setEffDamage(Effect effect) {
    switch(effect){
        case BURNING:
            CUR_BRN_DAM = std::max(0, BURN_DAMAGE * 2 - MAG_DEF);
            effectIntensity_DRW = "!!!!";
            break;
        case DROWNING:
            CUR_DRW_DAM = std::max(0, DROWN_DAMAGE - MAG_DEF);
            effectIntensity_ELC = "!!";
            break;
        case ELECTRIFIED:
            CUR_ELC_DAM = std::max(0, ELECTRIFY_DAMAGE - MAG_DEF);
            effectIntensity_RTD = "!!";
            break;
    }
}

void PokeGrass::Info() {
    std::cout << "[" << name << ", " << pokemonID << ", GRASS]" << std::endl;
}

void PokeGrass::getLevelBonus() {
    HP += 80 * level;
    ATK += 4 * level;
    MAG_DEF += 0 * level;
    PHY_DEF += 3 * level;
}

void PokeGrass::Reset() {
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

    HP = 800;
    ATK = 40;
    MAG_DEF = 0;
    PHY_DEF = 30;

    getLevelBonus();
}

void PokeGrass::setArenaEff(Arena arena) {
    if(!isArenaEffected()) {
        switch(arena)
        {
            case FOREST:
                HP += 100; ATK += 10; arenaBuff = '+';
                break;
            case MAGMA:
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
}

void PokeGrass::updateEffDamage() {
    if (isBurning()){
        CUR_BRN_DAM = std::max(0, BURN_DAMAGE * 2 - MAG_DEF);
        effectIntensity_DRW = "!!!!";
    }
    if(isDrowning()){
        CUR_DRW_DAM = std::max(0, DROWN_DAMAGE - MAG_DEF);
        effectIntensity_ELC = "!!";
    }
    if(isElectrified()) {
        CUR_ELC_DAM = std::max(0, ELECTRIFY_DAMAGE - MAG_DEF);
        effectIntensity_RTD = "!!";
    }
}

