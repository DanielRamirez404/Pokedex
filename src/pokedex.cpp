#include "pokedex.h"
#include "pokemon.h"
#include "dynamic-array.h"
#include "menu.h"
#include "input.h"
#include "userstring.h"
#include "cppsafeio.h"
#include <iostream>
#include <fstream>
#include <string>

bool isThereLoadblePokemonData() {
  std::ifstream readPokedex{"pokedex.txt"};
  std::string textLine{};
  bool isThereLoadblePokemonData{};
  while (std::getline(readPokedex, textLine)) {
    isThereLoadblePokemonData = (textLine == "[POKEDEX DATA AVAILABLE]") ? true : false;
    break;
  }
  readPokedex.close();
  return isThereLoadblePokemonData;
}

void readPokemonData(dynamic_array<pokemon>& pokedex) {
  std::ifstream readPokedex{"pokedex.txt"};
  std::string textLine{};
  while (std::getline(readPokedex, textLine)) {
    if (textLine[0] == '#') {
      int number = { stoi(getWordInSentence(textLine, 2)) };
      std::string name = { getWordInSentence(textLine, 3) };
      std::string types = { getWordByCharLimits(textLine, '[', ']') };
      pokemon readablePokemon{number, name, types};
      pokedex.add(readablePokemon);
    }
  }
  readPokedex.close();
}

void writeDefaultMessageToTextFile() {
  std::ofstream writeToPokedex{"pokedex.txt"};
  writeToPokedex << "[POKEDEX DATA AVAILABLE]\n\n";
  writeToPokedex.close();
}

void addPokemon(dynamic_array<pokemon>& pokedex) {
  std::string name{ inputPokemonName() };
  int number { inputPokemonNumber() };
  std::string types{ inputPokemonTypes() };
  pokemon pokemonToAdd{number, name, types};
  isPokemonAddable(pokedex, pokemonToAdd) ? pokedex.add(pokemonToAdd) : printNotAddablePokemonMessage();
  askUserToAddAnotherPokemon(pokedex);
}



void savePokedexData(dynamic_array<pokemon>& pokedex) {
  remove("pokedex.txt");
  writeDefaultMessageToTextFile();
  loopAndSavePokemonData(pokedex);
}

bool isPokedexEmpty(dynamic_array<pokemon>& pokedex) {
  return (pokedex.get_size() == 0);
}

void loopAndSavePokemonData(dynamic_array<pokemon>& pokedex) {
  std::ofstream writeToTextFile{"pokedex.txt", std::ios::app};
  for (int i = 0; i < pokedex.get_size(); i++) {
    writeToTextFile << "# " << pokedex[i].nationalNumber << ' ' << pokedex[i].name << ' ' << pokedex[i].types << '\n'; 
  }
  writeToTextFile.close();
}

void printPokedexData(dynamic_array<pokemon> pokedex) {
  for (int i = 0; i < pokedex.get_size(); i++)
    std::cout << "#" << pokedex[i].nationalNumber << ' ' << pokedex[i].name << ' ' << pokedex[i].types << '\n';
}

void sortPokedex(dynamic_array<pokemon>& pokedex) {
  int arraySize = pokedex.get_size() - 1;
  for (int i = 0; i < arraySize; i++) 
    for (int j = 0; j < arraySize - i; j++)
      if (pokedex[j].nationalNumber > pokedex[j + 1].nationalNumber)
        std::swap(pokedex[j], pokedex[j + 1]);
}

void erasePokedexData(dynamic_array<pokemon>& pokedex) {
  std::ofstream temp{"temp.txt"};
  temp << "[NO AVAILABLE DATA]\n\n";
  temp.close();
  remove("pokedex.txt");
  rename("temp.txt", "pokedex.txt");
  dynamic_array<pokemon> tempPokedex{};
  pokedex = tempPokedex;
  printSuccessfulDeletionMessage();
}

bool isPokemonAddable(dynamic_array<pokemon>& pokedex, pokemon& pokemonToAdd) {
  if (pokemonToAdd.types == "INVALID_TYPE" || pokemonToAdd.nationalNumber < 0)
    return false;
  for (int i = 0; i < pokedex.get_size(); i++)
    if (pokemonToAdd.name == pokedex[i].name || pokemonToAdd.nationalNumber == pokedex[i].nationalNumber)
      return false;
  return true;
}

void askUserToAddAnotherPokemon(dynamic_array<pokemon>& pokedex) {
  std::cout << "DO YOU WANT TO ADD ANOTHER POKEMON? (y/n)\n";
  if (CppSafeIO::parseYesNoInput()) 
    addPokemon(pokedex);
}


