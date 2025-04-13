#pragma once
#include "pokemon.h"
#include "dynamic-array.h"

bool isThereLoadblePokemonData();
void readPokemonData(dynamic_array<pokemon>& pokedex);
void writeDefaultMessageToTextFile();
void addPokemon(dynamic_array<pokemon>& pokedex);

void savePokedexData(dynamic_array<pokemon>& pokedex);
bool isPokedexEmpty(dynamic_array<pokemon>& pokedex);
void loopAndSavePokemonData(dynamic_array<pokemon>& pokedex);
void printPokedexData(dynamic_array<pokemon> pokedex);
void sortPokedex(dynamic_array<pokemon>& pokedex);
void erasePokedexData(dynamic_array<pokemon>& pokedex);

bool isPokemonAddable(dynamic_array<pokemon>& pokedex, pokemon& pokemonToAdd);
void askUserToAddAnotherPokemon(dynamic_array<pokemon>& pokedex);
