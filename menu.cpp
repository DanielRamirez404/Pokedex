#include "menu.h"
#include "userinput.h"
#include <iostream>

void printMainMenu() {
  std::cout << "----------------------------------------------\n";
  std::cout << "                   POKEDEX\n";
  std::cout << "----------------------------------------------\n";
  std::cout << "1) ENTER A NEW POKEMON\n";
  std::cout << "2) SEE CURRENT POKEMON DATA\n";
  std::cout << "3) ERASE ALL CURRENT POKEMON DATA\n";
  std::cout << "4) EXIT\n";
  std::cout << "----------------------------------------------\n";
}

void printNotAddablePokemonMessage() {
  std::cout << "SORRY, SEEMS LIKE YOUR POKEMON IS NOT ADDABLE\n";
  std::cout << "THIS MIGHT BE EITHER BEACAUSE IT\'S CONFLICTIVE\n";
  std::cout << "OR BEACAUSE OF A WRONG INPUT\n";
  pressAnyToContinue();
}

void printNoDataAvailableError() {
  std::cout << "SORRY, SEEMS LIKE YOUR POKEDEX HAS NO DATA\n";
  std::cout << "THEREFORE, NOTHING CAN BE PRINTED\n";
}

bool confirmDeletion() {
  std::cout << "----------------------------------------------\n";
  std::cout << "ARE YOU SURE YOU WANT TO ERASE\n";
  std::cout << "ALL POKEDEX DATA? (y/n)\n";
  bool userInput{ ynInput() };
  return userInput;
}

void printSuccessfulDeletionMessage() {
  std::cout << "----------------------------------------------\n";
  std::cout << "YOUR POKEDEX DATA HAS BEEN SUCCESSFULLY ERASED\n";
}

void printExitMessage() {
  std::cout << "----------------------------------------------\n";
  std::cout << "            SEE YOU NEXT TIME!\n";
  std::cout << "----------------------------------------------\n";
}
