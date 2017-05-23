//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include "Trainer.h"
#include "Tournament.h"

Tournament::Tournament(const std::string &tournamentName)
    : tournamentName(tournamentName) {}

Tournament::~Tournament() {

}

void Tournament::registerTrainers(const std::vector<Trainer *> &trainers) {
    this->trainers = trainers;
}

Trainer *Tournament::commence() {
    return NULL;
}

int Tournament::duelBetween(Trainer *trainer1, Trainer *trainer2, Arena currentArena) {
    return 0;
}

const std::string &Tournament::getTournamentName() const {
    return tournamentName;
}

int Tournament::duelBetween(Pokemon *pokemon1, Pokemon *pokemon2, Arena currentArena) {
    pokemon1->setArenaEff(currentArena);
    pokemon2->setArenaEff(currentArena);
    while(1) {

        std::cout << "            " << pokemon1->getName() << "(" << pokemon1->getHP() << ")"
             << " hit " << pokemon2->getName() << "(" << pokemon2->getHP() << ")"
             << " " << pokemon1->calculateDamage(pokemon2) << "(" << pokemon1->getArenaEff() << ")" << std::endl;

        pokemon1->attackTo(pokemon2, currentArena);

        if(checkWinner(pokemon1, pokemon2) != "NoWinner"){
            std::cout << "        " << "WinnerP:" << checkWinner(pokemon1,pokemon2) << std::endl;
            break;
        }

        if(pokemon2->isEfected()){
            std::cout << "            " << pokemon2->getName() << "(" << pokemon2->getHP() << ")" << " is " << pokemon2->getEffStatus() << pokemon2->getEffIntensity() << std::endl;
            pokemon2->getEffDamage();
        }

        if(checkWinner(pokemon1, pokemon2) != "NoWinner"){
            std::cout << "        " << "WinnerP:" << checkWinner(pokemon1,pokemon2) << std::endl;
            break;
        }

        std::cout << "            " << pokemon2->getName() << "(" << pokemon2->getHP() << ")"
                  << " hit " << pokemon1->getName() << "(" << pokemon1->getHP() << ")"
                  << " " << pokemon2->calculateDamage(pokemon1) << "(" << pokemon2->getArenaEff() << ")" << std::endl;

        pokemon2->attackTo(pokemon1, currentArena);

        if(checkWinner(pokemon2, pokemon1) != "NoWinner"){
            std::cout << "        " << "WinnerP:" << checkWinner(pokemon2,pokemon1) << std::endl;
            break;
        }

        if(pokemon1->isEfected()){
            std::cout << "            " << pokemon1->getName() << "(" << pokemon1->getHP() << ")" << " is " << pokemon1->getEffStatus() << pokemon1->getEffIntensity() << std::endl;
            pokemon1->getEffDamage();
        }

        if(checkWinner(pokemon2, pokemon1) != "NoWinner"){
            std::cout << "        " << "WinnerP:" << checkWinner(pokemon2,pokemon1) << std::endl;
            break;
        }

    }
}

std::string Tournament::checkWinner(Pokemon *pokemon1, Pokemon *pokemon2) {
    if(pokemon1->isDead())
        return pokemon2->getName();
    else if(pokemon2->isDead())
        return pokemon1->getName();
    else
        return "NoWinner";
}

