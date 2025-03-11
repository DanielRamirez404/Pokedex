#ifndef MAIN
#define MAIN
#include "dynamic-array.h"
#include <string>

struct pokemon {
  int nationalNumber{};
  std::string name{};
  std::string types{};
};

bool isThereLoadblePokemonData();
void readPokemonData(dynamic_array<pokemon>& pokedex);
void writeDefaultMessageToTextFile();
void addPokemon(dynamic_array<pokemon>& pokedex);
std::string inputPokemonName();
int inputPokemonNumber();
std::string inputPokemonTypes();
std::string inputMonotypePokemonType();
std::string inputNonMonotypePokemonTypes();
bool isTypeValid(std::string type);
bool isPokemonAddable(dynamic_array<pokemon>& pokedex, pokemon& pokemonToAdd);
void askUserToAddAnotherPokemon(dynamic_array<pokemon>& pokedex);
void savePokedexData(dynamic_array<pokemon>& pokedex);
bool isPokedexEmpty(dynamic_array<pokemon>& pokedex);
void loopAndSavePokemonData(dynamic_array<pokemon>& pokedex);
void printPokedexData(dynamic_array<pokemon> pokedex);
void sortPokedex(dynamic_array<pokemon>& pokedex);
void erasePokedexData(dynamic_array<pokemon>& pokedex);

#endif
