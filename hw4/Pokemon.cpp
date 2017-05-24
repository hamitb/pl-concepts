//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <iostream>
#include "Pokemon.h"

Pokemon::Pokemon(int pokemonID, const std::string &name) {
    this->pokemonID = pokemonID;
    this->name = name;

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

    level = 0;
    effected = false;
    arenaEffected = false;
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

void Pokemon::setEffDamage(Effect effect) {
    CUR_BRN_DAM = 0;
    CUR_DRW_DAM = 0;
    CUR_ELC_DAM = 0;
    CUR_RTD_DAM = 0;
    CUR_ATT_DAM = 0;
}

bool Pokemon::isDead() {
    return dead;
}

void Pokemon::updateDeadStatus() {
    if(!dead)
        dead = HP <= 0;
}

void Pokemon::setAttDamage(int damage) {
    CUR_ATT_DAM = damage;
}

void Pokemon::applyEffect(Effect effect, Pokemon* target) {
     switch(effect){
        case BURNING:
            if(!target->isBurning()){
                target->setBurning(true);
                target->setEffDamage(effect);
            }
            break;
        case DROWNING:
            if(!target->isDrowning()){
                target->setDrowning(true);
                target->setEffDamage(effect);
            }
            break;
        case ELECTRIFIED:
            if(!target->isElectrified()) {
                target->setElectrified(true);
                target->setEffDamage(effect);
            }
            break;
        case ROOTED:
            if(!target->isRooted()){
                target->setRooted(true);
                target->setEffDamage(effect);
            }
            break;
     }

}

int Pokemon::getAttDamage() {
    HP = std::max(HP - CUR_ATT_DAM, 0);
    updateDeadStatus();
}

void Pokemon::getEffDamage(Effect effect) {
    switch(effect) {
        case BURNING:
            std::cout << "\t\t\t" << getName() << "(" << getHP() << ") " << Helpers::getEffectName(effect) << getEffIntensity(effect) << std::endl;
            HP = std::max(HP - CUR_BRN_DAM, 0);
            break;
        case DROWNING:
            std::cout << "\t\t\t" << getName() << "(" << getHP() << ") " << Helpers::getEffectName(effect) << getEffIntensity(effect) << std::endl;
            HP = std::max(HP - CUR_DRW_DAM, 0);
            break;
        case ELECTRIFIED:
            std::cout << "\t\t\t" << getName() << "(" << getHP() << ") " << Helpers::getEffectName(effect) << getEffIntensity(effect) << std::endl;
            HP = std::max(HP - CUR_ELC_DAM, 0);
            break;
        case ROOTED:
            std::cout << "\t\t\t" << getName() << "(" << getHP() << ") " << Helpers::getEffectName(effect) << getEffIntensity(effect) << std::endl;
            HP = std::max(HP - CUR_RTD_DAM, 0);
            break;
    }

    updateDeadStatus();
}

char Pokemon::getArenaEff() {
    return arenaBuff;
}

int Pokemon::calculateDamage(Pokemon *target){
    return std::max(1, ATK - target->getPHY_DEF());
}

bool Pokemon::isEfected() {
    return effected;
}

bool Pokemon::isArenaEffected() {
    return arenaEffected;
}

std::string Pokemon::getEffIntensity(Effect effect) {
    switch(effect) {
        case BURNING:
            return effectIntensity_BRN;
        case DROWNING:
            return effectIntensity_DRW;
        case ELECTRIFIED:
            return effectIntensity_ELC;
        case ROOTED:
            return effectIntensity_RTD;
    }
}

void Pokemon::setEffected(bool effected) {
    this->effected = effected;
}

void Pokemon::updateEffDamage() {

}

void Pokemon::Info() {
    std::cout << "Name:" << getName() << std::endl
              << "effected? " << isEfected() << std::endl
              << "burning? " << isBurning() << " dam: " << CUR_BRN_DAM << std::endl
              << "drowning? " << isDrowning() << " dam: " << CUR_DRW_DAM << std::endl
              << "electried? " << isElectrified() << " dam: " << CUR_ELC_DAM << std::endl
              << "rooted? " << isRooted() << " dam: " << CUR_RTD_DAM << std::endl;
}
