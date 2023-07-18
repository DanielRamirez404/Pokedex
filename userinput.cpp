#include "userinput.h"
#include <iostream>
#include <conio.h>

bool ynInput() {
  bool choice{};
  char userInput{ getUserInput<char>() };
  switch (tolower(userInput)) {
    case 'y':
      choice = true;
      break;
    case 'n':
      choice = false;
      break;
    default:
      printBadInputError();
      pressAnyToContinue();
      ynInput();
      break;
  }
  return choice;
}

void printBadInputError() {
  std::cout << "----------------------------------------------\n";
  std::cout << "OH-OH, IT SEEMS THAT YOUR INPUT ISN'T VALID.\n";
  std::cout << "PLEASE, TRY AGAIN.\n";
}

void pressAnyToContinue() {
  std::cout << "----------------------------------------------\n";
  std::cout << "       NOW, PRESS ANY KEY TO CONTINUE\n";
  std::cout << "----------------------------------------------\n";
  getch();
}
