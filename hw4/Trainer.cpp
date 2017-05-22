//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <vector>
#include "Enums.h"
#include "Trainer.h"

Trainer::Trainer(int trainerID, const std::string &name, Arena favoriteArena, std::vector<Pokemon *> &pokemons)
    : name(name), trainerID(trainerID){ this->favoriteArena = favoriteArena; this->pokemons = pokemons; }

Trainer::~Trainer() {
    for(int i = 0; i < pokemons.size(); i++) {
        if(pokemons[i])
            delete pokemons[i];
    }
}

int Trainer::getTrainerID() const {
    return trainerID;
}

const std::string &Trainer::getName() const {
    return name;
}

Arena Trainer::getFavoriteArena() const {
    return favoriteArena;
}
