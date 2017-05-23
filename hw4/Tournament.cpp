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
    int t1Score = 0;
    int t2Score = 0;
    int lastWinner = 2;
    int winnerTrainer;
    std::string winnerName;
    std::string arenaName = Helpers::getArenaName(currentArena);

    trainer1->resetDP();
    trainer2->resetDP();
    std::cout << "    " << trainer1->getName() << " vs " << trainer2->getName()
              << ": " << arenaName << std::endl;

    while( (trainer1->getDPCount() != 0)
        && (trainer2->getDPCount() != 0)) {

        int winner;

        Pokemon* p1 = trainer1->getNewDP();
        Pokemon* p2 = trainer2->getNewDP();

        if(lastWinner == 1) {
            winner = duelBetween(p2,p1, currentArena);
        } else {
            winner = duelBetween(p1,p2, currentArena);
        }

        if ((lastWinner == 2) && (winner == 1)){
            p1->levelUp();
            p1->updateEffDamage();
            p2->Reset();

            trainer2->replaceDP();
            lastWinner = 1;
        } else if ((lastWinner == 2) && (winner == -1)) {
            p2->levelUp();
            p2->updateEffDamage();
            p1->Reset();

            trainer1->replaceDP();
            lastWinner = 2;
        } else if ((lastWinner == 1) && (winner == 1)) {
            p2->levelUp();
            p2->updateEffDamage();
            p1->Reset();

            trainer1->replaceDP();
            lastWinner = 2;
        } else if ((lastWinner == 1) && (winner == -1)) {
            p1->levelUp();
            p1->updateEffDamage();
            p2->Reset();

            trainer2->replaceDP();
            lastWinner = 1;
        }

    }

    winnerTrainer = trainer1->getDPCount() != 0 ? 1 : -1;
    winnerName = winnerTrainer == 1 ? trainer1->getName() : trainer2->getName();
    std::cout << "    " << "WinnerT" << winnerName << std::endl;

    return winnerTrainer;
}

const std::string &Tournament::getTournamentName() const {
    return tournamentName;
}

int Tournament::duelBetween(Pokemon *pokemon1, Pokemon *pokemon2, Arena currentArena) {
    pokemon1->setArenaEff(currentArena);
    pokemon2->setArenaEff(currentArena);
    while(1) {
        int winner;

        std::cout << "            " << pokemon1->getName() << "(" << pokemon1->getHP() << ")"
             << " hit " << pokemon2->getName() << "(" << pokemon2->getHP() << ")"
             << " " << pokemon1->calculateDamage(pokemon2) << "(" << pokemon1->getArenaEff() << ")" << std::endl;

        pokemon1->attackTo(pokemon2, currentArena);


        if((winner = checkWinner(pokemon1, pokemon2))){
            std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
            std::cout << "        " << "WinnerP:" << winnerName << std::endl;
            return winner;
        }

        if(pokemon2->isEfected()){
            if(pokemon2->isBurning())
                pokemon2->getEffDamage(BURNING);
            if((winner = checkWinner(pokemon1, pokemon2))){
                std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
                std::cout << "        " << "WinnerP:" << winnerName << std::endl;
                return winner;
            }
            if(pokemon2->isDrowning())
                pokemon2->getEffDamage(DROWNING);
            if((winner = checkWinner(pokemon1, pokemon2))){
                std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
                std::cout << "        " << "WinnerP:" << winnerName << std::endl;
                return winner;
            }
            if(pokemon2->isElectrified())
                pokemon2->getEffDamage(ELECTRIFIED);
            if((winner = checkWinner(pokemon1, pokemon2))){
                std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
                std::cout << "        " << "WinnerP:" << winnerName << std::endl;
                return winner;
            }
            if(pokemon2->isRooted())
                pokemon2->getEffDamage(ROOTED);
        }

        std::cout << "            " << pokemon2->getName() << "(" << pokemon2->getHP() << ")"
                  << " hit " << pokemon1->getName() << "(" << pokemon1->getHP() << ")"
                  << " " << pokemon2->calculateDamage(pokemon1) << "(" << pokemon2->getArenaEff() << ")" << std::endl;

        pokemon2->attackTo(pokemon1, currentArena);

        if((winner = checkWinner(pokemon1, pokemon2))){
            std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
            std::cout << "        " << "WinnerP:" << winnerName << std::endl;
            return winner;
        }

        if(pokemon1->isEfected()){
            if(pokemon1->isBurning())
                pokemon1->getEffDamage(BURNING);
            if((winner = checkWinner(pokemon1, pokemon2))){
                std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
                std::cout << "        " << "WinnerP:" << winnerName << std::endl;
                return winner;
            }
            if(pokemon1->isDrowning())
                pokemon1->getEffDamage(DROWNING);
            if((winner = checkWinner(pokemon1, pokemon2))){
                std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
                std::cout << "        " << "WinnerP:" << winnerName << std::endl;
                return winner;
            }
            if(pokemon1->isElectrified())
                pokemon1->getEffDamage(ELECTRIFIED);
            if((winner = checkWinner(pokemon1, pokemon2))){
                std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
                std::cout << "        " << "WinnerP:" << winnerName << std::endl;
                return winner;
            }
            if(pokemon1->isRooted())
                pokemon1->getEffDamage(ROOTED);
            if((winner = checkWinner(pokemon1, pokemon2))){
                std::string winnerName = winner == 1 ? pokemon1->getName() : pokemon2->getName();
                std::cout << "        " << "WinnerP:" << winnerName << std::endl;
                return winner;
            }
        }
    }
}

int Tournament::checkWinner(Pokemon *pokemon1, Pokemon *pokemon2) {
    if(pokemon1->isDead())
        return -1;
    else if(pokemon2->isDead())
        return 1;
    else
        return 0;
}


