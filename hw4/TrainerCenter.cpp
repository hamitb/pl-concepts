//
// Created by Hamit Burak Emre on 19/05/17.
//

#include <string>
#include <vector>
#include <fstream>
#include "Trainer.h"
#include "TrainerCenter.h"

TrainerCenter::TrainerCenter(const std::string &inputFileName) {
    int trainerCount;
    int pokemonCount;
    std::string line;
    std::ifstream inputFile;

    inputFile.open(inputFileName);

    getline(inputFile, line);
    trainerCount = parseTrainerCount(line);

    getline(inputFile, line);
    pokemonCount = parsePokemonCount(line);

    getline(inputFile, line);

    for(int i = 0; i < trainerCount; i++) {
        std::string tstring;
        std::string pstring;
        std::vector<Pokemon*> pokemons;
        getline(inputFile, tstring);

        for(int j = 0; j < pokemonCount; j++) {
            getline(inputFile, pstring);
            Pokemon* pokemon = parsePokemon(pstring);
            pokemons.push_back(pokemon);
        }

        Trainer* trainer = parseTrainer(tstring, pokemons);
        trainers.push_back(trainer);
        getline(inputFile, line);
    }
}

TrainerCenter::~TrainerCenter() {
    for(int i = 0; i < trainers.size(); i++) {
        if(trainers[i])
            delete trainers[i];
    }
}

std::vector<Trainer *> &TrainerCenter::getAllTrainers() {
    return trainers;
}

Trainer *TrainerCenter::getTrainerWithID(int trainerID) {
    for(int i = 0; i < trainers.size(); i++) {
        if(trainers[i]->getTrainerID() == trainerID)
            return trainers[i];
    }
}

int TrainerCenter::parsePokemonCount(std::string line) {
    int result;
    char * cstr = new char [line.length()+1];

    strcpy(cstr, line.c_str());

    sscanf(cstr, "Pokemon Count:%d", &result);

    delete[] cstr;

    return result;
}

int TrainerCenter::parseTrainerCount(std::string line) {
    int result;
    char * cstr = new char [line.length()+1];

    strcpy(cstr, line.c_str());

    sscanf(cstr, "Trainer Count:%d", &result);

    delete[] cstr;

    return result;
}

Pokemon *TrainerCenter::parsePokemon(std::string line) {
    Pokemon* pokemon;
    char * cstr = new char [line.length()];
    int id;
    char name[100];
    char type[100];
    std::string find = "::";
    std::string replace = " ";

    for(std::string::size_type i = 0; (i = line.find(find, i)) != std::string::npos;){
        line.replace(i, find.length(), replace);
        i += replace.length();
    }

    strcpy(cstr, line.c_str());

    sscanf(cstr, "%d %s %s", &id, name, type);
    if(strncmp(name,"FIRE", strlen(name)) == 0)
        pokemon = new PokeFire(id, name);
    else if(strncmp(name,"WATER", strlen(name)) == 0)
        pokemon = new PokeWater(id, name);
    else if(strncmp(name,"ELECTRIC", strlen(name)) == 0)
        pokemon = new PokeElectric(id, name);
    else if(strncmp(name,"GRASS", strlen(name)) == 0)
        pokemon = new PokeGrass(id, name);
    else if(strncmp(name,"FLYING", strlen(name)) == 0)
        pokemon = new PokeFlying(id, name);
    else
        pokemon = new PokeFire(id, name);

    delete[] cstr;

    return pokemon;
}

Trainer *TrainerCenter::parseTrainer(std::string line, std::vector<Pokemon*> pokemons) {
    Trainer* trainer;
    char * cstr = new char [line.length()];
    int id;
    char name[100];
    char favAreaS[100];
    Arena favArea;
    std::string find = "--";
    std::string replace = " ";

    for(std::string::size_type i = 0; (i = line.find(find, i)) != std::string::npos;){
        line.replace(i, find.length(), replace);
        i += replace.length();
    }

    strcpy(cstr, line.c_str());

    sscanf(cstr, "%d %s %s", &id, name, favAreaS);

    if(strncmp(favAreaS,"Sky", strlen(favAreaS)) == 0)
        favArea = SKY;
    else if(strncmp(name,"Magma", strlen(favAreaS)) == 0)
        favArea = MAGMA;
    else if(strncmp(name,"Ocean", strlen(favAreaS)) == 0)
        favArea = OCEAN;
    else if(strncmp(name,"ElectriCity", strlen(favAreaS)) == 0)
        favArea = ELECTRICITY;
    else if(strncmp(name,"Forest", strlen(favAreaS)) == 0)
        favArea = FOREST;
    else
        favArea = STADIUM;



    trainer = new Trainer(id, name, favArea, pokemons);

    delete[] cstr;

    return trainer;
}
