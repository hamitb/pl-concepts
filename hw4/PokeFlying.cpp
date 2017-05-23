//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <iostream>
#include "Pokemon.h"
#include "PokeFlying.h"

PokeFlying::PokeFlying(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 650;
    ATK = 55;
    MAG_DEF = 0;
    PHY_DEF = 15;
    EFFECT = NOTHING;

    isDoubled = false;
}

void PokeFlying::attackTo(Pokemon *target, Arena currentArena) {

}

void PokeFlying::levelUp() {
    level ++;
    getLevelBonus();
}

void PokeFlying::setElectrified(bool electrified) {
    this->electrified = false;
}

void PokeFlying::setDrowning(bool drowning) {
    this->drowning = false;
}

void PokeFlying::setBurning(bool burning) {
    this->burning = false;
}

void PokeFlying::setRooted(bool rooted) {
    this->rooted = false;
}

void PokeFlying::Info() {
    std::cout << "[" << name << ", " << pokemonID << ", FLYING]" << std::endl;
}

void PokeFlying::Reset() {
    CUR_EFF_DAM = 0;
    CUR_ATT_DAM = 0;
    burning = false;
    drowning = false;
    electrified = false;
    rooted = false;
    dead = false;

    HP = 650;
    ATK = 55;
    MAG_DEF = 0;
    PHY_DEF = 15;

    getLevelBonus();
}

void PokeFlying::getLevelBonus() {
    HP += 65 * level;
    ATK += 5 * level;
    MAG_DEF += 0 * level;
    PHY_DEF += 3 * level;
}

void PokeFlying::setArenaEff(Arena arena) {
    switch(arena)
    {
        case SKY:
            HP += 100; ATK += 10; arenaBuff = 1;
            break;
        case OCEAN:
            HP -= 100; ATK -= 10; arenaBuff = -1;
            break;
        case ELECTRICITY:
            HP -= 100; ATK -= 10; arenaBuff = -1;
            break;
        case STADIUM:
            arenaBuff = 0;
    }
}
