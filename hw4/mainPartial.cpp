#include "PokeFire.h"
#include "PokeWater.h"
#include "PokeElectric.h"
#include "PokeGrass.h"
#include "PokeFlying.h"
#include "TrainerCenter.h"
#include "Tournament.h"

#include <iostream>
#include <vector>

bool attributeTest();
bool effectTest();
bool trainerCenterTest();
bool DuelTest();

void introduceYourself(Pokemon *pokemon);

int main(int argc, char** argv)
{
	if(!attributeTest() || !effectTest() || !DuelTest()) // || aTest() || anotherTest() ...
	{
		return -1;
	}

	return 0;
}

bool trainerCenterTest() {
    TrainerCenter newCenter("2Trainers.txt");

    newCenter.Info();
    return true;
}

bool DuelTest() {
    TrainerCenter newCenter("2Trainers.txt");
    Tournament aTournament("sample tournament");
    std::vector<Trainer *> trainers = newCenter.getAllTrainers();

    std::cout << aTournament.getWinnerTrainer(trainers[0], trainers[1]) << std::endl;

    return true;
}


bool attributeTest()
{
	PokeFire fire(0, "Charmander");
	PokeWater water(1, "Psyduck");
	PokeElectric electric(2, "Pikachu");
	PokeGrass grass(3, "Bulbasaur");
	PokeFlying flying(4, "Zapdos");

	introduceYourself(&fire);
	introduceYourself(&water);
	introduceYourself(&electric);
	introduceYourself(&grass);
	introduceYourself(&flying);

	if((fire.getHP() != 600)
	|| (water.getHP() != 700)
	|| (electric.getHP() != 500)
	|| (grass.getHP() != 800)
	|| (flying.getHP() != 650))
	{
		std::cout << "Problem in getHP" << std::endl;

		return false;
	}
	// ...
	// Same for ATK, MAG_DEF and PHY_DEF.

	fire.levelUp();
	water.levelUp();
	electric.levelUp();
	grass.levelUp();
	flying.levelUp();

	if((fire.getHP() != 660)
	|| (water.getHP() != 770)
	|| (electric.getHP() != 550)
	|| (grass.getHP() != 880)
	|| (flying.getHP() != 715))
	{
		std::cout << "Problem in getHP after leveled up" << std::endl;

		return false;
	}
	// ...
	// Same for ATK, MAG_DEF and PHY_DEF.

	return true;
}

bool effectTest()
{
	PokeFire fire(0, "Charmander");
	PokeWater water(1, "Psyduck");
	PokeElectric electric(2, "Pikachu");
	PokeGrass grass(3, "Bulbasaur");
	PokeFlying flying(4, "Zapdos?");

	PokeFire anotherFire(5, "Charizard");

	Arena arena = STADIUM;

	// You are free to print anything in attackTo, only the after-effects will be tested separately.
	fire.attackTo(&water, arena);
	fire.attackTo(&electric, arena);
	fire.attackTo(&grass, arena);
	fire.attackTo(&flying, arena);
	fire.attackTo(&anotherFire, arena);

	if(!water.isBurning() || !electric.isBurning() || !grass.isBurning() || flying.isBurning() || anotherFire.isBurning())
	{
		std::cout << "Problem in setBurning" << std::endl;

		return false;
	}

	// ...
	// Same for DROWNING, ELECTRIFIED and ROOTED.

	return true;
}

void introduceYourself(Pokemon *pokemon)
{
	std::cout << pokemon->getPokemonID() << " " << pokemon->getName() << std::endl;
}