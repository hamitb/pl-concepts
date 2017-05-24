cmake_minimum_required(VERSION 3.7)
project(hw4)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Pokemon.cpp PokeWater.cpp PokeElectric.cpp PokeFire.cpp PokeFlying.cpp PokeGrass.cpp Trainer.cpp TrainerCenter.cpp Tournament.cpp)
add_executable(hw4 ${SOURCE_FILES})