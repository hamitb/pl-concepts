//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <vector>
#include "Trainer.h"
#include "Tournament.h"

Tournament::Tournament(const std::string &tournamentName) {

}

Tournament::~Tournament() {

}

void Tournament::registerTrainers(const std::vector<Trainer *> &trainers) {

}

Trainer *Tournament::commence() {
    return NULL;
}

int Tournament::duelBetween(Trainer *trainer1, Trainer *trainer2, Arena currentArena) {
    return 0;
}

const std::string &Tournament::getTournamentName() const {
    return <#initializer#>;
}

int Tournament::duelBetween(Pokemon *pokemon1, Pokemon *pokemon2, Arena currentArena) {
    return 0;
}
