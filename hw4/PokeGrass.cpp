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
    applyEffect(EFFECT, target);
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
        CUR_EFF_DAM = BURN_DAMAGE * 2;
        isDoubled = true;
    }
    else if(drowning){
        CUR_EFF_DAM = DROWN_DAMAGE;
        isDoubled = false;
    }
    else if(electrified){
        CUR_EFF_DAM = ELECTRIFY_DAMAGE;
        isDoubled = false;
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
            HP += 100; ATK += 10; arenaBuff = 1;
            break;
        case MAGMA:
            HP -= 100; ATK -= 10; arenaBuff = -1;
            break;
        case SKY:
            HP -= 100; ATK -= 10; arenaBuff = -1;
            break;
        case STADIUM:
            arenaBuff = 0;
    }
}

