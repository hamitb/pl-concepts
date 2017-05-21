//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include "Pokemon.h"
#include "PokeFlying.h"

PokeFlying::PokeFlying(int pokemonID, const std::string &name) : Pokemon(pokemonID, name) {
    HP = 600;
    ATK = 55;
    MAG_DEF = 0;
    PHY_DEF = 15;
}

void PokeFlying::attackTo(Pokemon *target, Arena currentArena) {

}

void PokeFlying::levelUp() {
    HP += 65;
    ATK += 5;
    MAG_DEF += 0;
    PHY_DEF += 3;
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
