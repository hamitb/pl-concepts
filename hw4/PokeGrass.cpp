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

void PokeGrass::setEffDamage() {
    if(burning){
        CUR_EFF_DAM = std::max(0, BURN_DAMAGE * 2 - MAG_DEF);
        effectIntensity = "!!!!";
    }
    else if(drowning){
        CUR_EFF_DAM = std::max(0, DROWN_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
    }
    else if(electrified){
        CUR_EFF_DAM = std::max(0, ELECTRIFY_DAMAGE - MAG_DEF);
        effectIntensity = "!!";
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

    HP = 800;
    ATK = 40;
    MAG_DEF = 0;
    PHY_DEF = 30;

    getLevelBonus();
}

void PokeGrass::setArenaEff(Arena arena) {
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

