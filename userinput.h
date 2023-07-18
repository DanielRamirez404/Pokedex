#ifndef USER_INPUT
#define USER_INPUT
#include <iostream>

template <typename T> T getUserInput() {
  std::cout << "INPUT: ";
  T userInput{};
  std::cin >> userInput;
  std::cout << "----------------------------------------------\n";
  return userInput;
}

bool ynInput();
void printBadInputError();
void pressAnyToContinue();

#endif
