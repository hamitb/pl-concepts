#ifndef TRAINER_CENTER_H
#define TRAINER_CENTER_H

#include "Trainer.h"
#include "Pokemon.h"
#include "PokeFire.h"
#include "PokeWater.h"
#include "PokeElectric.h"
#include "PokeGrass.h"
#include "PokeFlying.h"
#include <vector>
#include <string>

class TrainerCenter
{
public:
	// Public Methods

	TrainerCenter(const std::string& inputFileName);
    ~TrainerCenter();
    
	std::vector<Trainer*>& getAllTrainers();

	Trainer* getTrainerWithID(int trainerID);

	// Own Methods

private:
	// Own Attributes
	std::vector<Trainer*> trainers;

	int parsePokemonCount(std::string line);
	int parseTrainerCount(std::string line);

	Pokemon* parsePokemon(std::string line);
	Trainer* parseTrainer(std::string line, std::vector<Pokemon*> pokemons);
};

#endif
