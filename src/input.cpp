#include "input.h"
#include "cppsafeio.h"
#include "userstring.h"
#include <iostream>
#include <string>

std::string inputPokemonName() {
  std::cout << "PLEASE, ADD THIS POKEMON\'S NAME\n";
  return uppercase(CppSafeIO::getInput<std::string>());
}

int inputPokemonNumber() {
  std::cout << "NOW, YOU CAN ADD ITS POKEDEX NUMBER\n";
  return CppSafeIO::getInput<int>();
}

std::string inputPokemonTypes() {
  std::cout << "IS IT A MONOTYPE POKEMON? (y/n)\n";
  return CppSafeIO::parseYesNoInput() ? inputMonotypePokemonType() : inputNonMonotypePokemonTypes();
}

std::string inputMonotypePokemonType() {
  std::cout << "INTRODUCE ITS TYPE\n";
  std::string type { uppercase(CppSafeIO::getInput<std::string>()) };
  return isTypeValid(type) ? '[' + type + ']' : "INVALID_TYPE";
}

std::string inputNonMonotypePokemonTypes() {
  std::string types[2]{};
  int arraySize { sizeof(types) / sizeof(std::string) };
  for (int i = 0; i < arraySize; i++) {
    std::cout << "INTRODUCE ITS TYPE #" << i + 1 << '\n';
    types[i] = uppercase(CppSafeIO::getInput<std::string>());
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

