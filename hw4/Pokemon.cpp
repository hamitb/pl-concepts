//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include "Pokemon.h"

Pokemon::Pokemon(int pokemonID, const std::string &name) {
    this->pokemonID = pokemonID;
    this->name = name;
}

Pokemon::~Pokemon() {

}

int Pokemon::getPokemonID() const {
    return pokemonID;
}

const std::string &Pokemon::getName() const {
    return name;
}

int Pokemon::getHP() const {
    return HP;
}

int Pokemon::getATK() const {
    return ATK;
}

int Pokemon::getMAG_DEF() const {
    return MAG_DEF;
}

int Pokemon::getPHY_DEF() const {
    return PHY_DEF;
}

bool Pokemon::isBurning() const {
    return burning;
}

bool Pokemon::isDrowning() const {
    return drowning;
}

bool Pokemon::isElectrified() const {
    return electrified;
}

bool Pokemon::isRooted() const {
    return rooted;
}

void Pokemon::setBurning(bool burning) {
    this->burning = burning;
}

void Pokemon::setDrowning(bool drowning) {
    this->drowning = drowning;
}

void Pokemon::setElectrified(bool electrified) {
    this->electrified = electrified;
}

void Pokemon::setRooted(bool rooted) {
    this->rooted = rooted;
}
