//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <vector>
#include "Enums.h"
#include "Trainer.h"

Trainer::Trainer(int trainerID, const std::string &name, Arena favoriteArena, std::vector<Pokemon *> &pokemons) {

}

Trainer::~Trainer() {

}

int Trainer::getTrainerID() const {
    return 0;
}

const std::string &Trainer::getName() const {
    return <#initializer#>;
}

Arena Trainer::getFavoriteArena() const {
    return SKY;
}
