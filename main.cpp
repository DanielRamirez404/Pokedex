#include "main.h"
#include "menu.h"
#include "dynamic-array.h"
#include "userstring.h"
#include "userinput.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
  dynamic_array<pokemon> pokedex{};
  isThereLoadblePokemonData() ? readPokemonData(pokedex) : writeDefaultMessageToTextFile();
  bool exitProgram{false};
  while (!exitProgram) {
    printMainMenu();
    doUserOption(exitProgram, pokedex);
    pressAnyToContinue();
  }
  printExitMessage();
  return 0;
}

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

void doUserOption(bool& exitProgram, dynamic_array<pokemon>& pokedex) {
  int userInput{ getUserInput<int>() };
  switch (userInput) {
    case 1:
      addPokemon(pokedex);
      sortPokedex(pokedex);
      savePokedexData(pokedex);
      break;
    case 2:
      isPokedexEmpty(pokedex) ? printNoDataAvailableError() : printPokedexData(pokedex);
      break;
    case 3:
      if (confirmDeletion())
        erasePokedexData(pokedex);
      break;
    case 4:
      exitProgram = true;
      break;
    default:
      printBadInputError();
      break;
  }
}

void addPokemon(dynamic_array<pokemon>& pokedex) {
  std::string name{ inputPokemonName() };
  int number { inputPokemonNumber() };
  std::string types{ inputPokemonTypes() };
  pokemon pokemonToAdd{number, name, types};
  isPokemonAddable(pokedex, pokemonToAdd) ? pokedex.add(pokemonToAdd) : printNotAddablePokemonMessage();
  askUserToAddAnotherPokemon(pokedex);
}

std::string inputPokemonName() {
  std::cout << "PLEASE, ADD THIS POKEMON\'S NAME\n";
  return uppercase(getUserInput<std::string>());
}

int inputPokemonNumber() {
  std::cout << "NOW, YOU CAN ADD ITS POKEDEX NUMBER\n";
  return getUserInput<int>();
}

std::string inputPokemonTypes() {
  std::cout << "IS IT A MONOTYPE POKEMON? (y/n)\n";
  return ynInput() ? inputMonotypePokemonType() : inputNonMonotypePokemonTypes();
}

std::string inputMonotypePokemonType() {
  std::cout << "INTRODUCE ITS TYPE\n";
  std::string type { uppercase(getUserInput<std::string>()) };
  return isTypeValid(type) ? '[' + type + ']' : "INVALID_TYPE";
}

std::string inputNonMonotypePokemonTypes() {
  std::string types[2]{};
  int arraySize { sizeof(types) / sizeof(std::string) };
  for (int i = 0; i < arraySize; i++) {
    std::cout << "INTRODUCE ITS TYPE #" << i + 1 << '\n';
    types[i] = uppercase(getUserInput<std::string>());
    if (!isTypeValid(types[i]))
      return "INVALID_TYPE";
  }
  return '[' + types[0] + " / " + types[1] + ']';
}

bool isTypeValid(std::string type) {
  std::string allPokemonTypes[18] 
    { "NORMAL", "FIRE", "WATER", "GRASS", "ELECTRIC", "ICE", "FIGHTING", "POISON", "GROUND", 
    "FLYING", "PSYCHIC", "BUG", "ROCK", "GHOST", "DARK", "DRAGON", "STEEL", "FAIRY" };
  int arraySize { sizeof(allPokemonTypes) / sizeof(std::string) };
  for (int i = 0; i < arraySize; i++)
    if (type == allPokemonTypes[i])
      return true;
  return false;
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
  if (ynInput()) 
    addPokemon(pokedex);
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
