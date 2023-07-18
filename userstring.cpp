#include "userstring.h"
#include <string>
#include <cassert>

std::string uppercase(std::string myString) {
  for (size_t i = 0; i < myString.size(); i++)
    myString[i] = toupper(myString[i]);
  return myString;
}

std::string getWordInSentence(std::string sentence, int wordNumber) {
  std::string word{""};
  int wordCounter{1};
  for (size_t i = 0; i < sentence.size(); i++) {
    if(sentence[i] == ' ') {
      wordCounter++;
      if (wordCounter > wordNumber) break;    
    } else {
      if (wordCounter == wordNumber) word += sentence[i];
    }
  }
  assert(word != "");
  return word;
}

std::string getWordByCharLimits(std::string sentence, char lowerLimit, char upperLimit) {
  std::string word{""};
  if (lowerLimit != upperLimit) {
    loopWordByDifferentCharLimits(word, sentence, lowerLimit, upperLimit);
  } else {
    loopWordBySameCharLimits(word, sentence, lowerLimit);
  }
  assert(word != "");
  return word;
}

void loopWordByDifferentCharLimits(std::string& word, std::string sentence, char lowerLimit, char upperLimit) {
  bool isCharBetweenLimits{false};
  for (size_t i = 0; i < sentence.size(); i++) {
    if (sentence[i] == lowerLimit) {
      isCharBetweenLimits = true;
    }
    if (isCharBetweenLimits) {
      word += sentence[i];
    }
    if (sentence[i] == upperLimit) {
      isCharBetweenLimits = false;
      break;
    }
  }
  assert(!isCharBetweenLimits);
}

void loopWordBySameCharLimits(std::string& word, std::string sentence, char delimiter) {
  int characterOcurrences{0};
  for (size_t i = 0; i < sentence.size(); i++) {
    if (sentence[i] == delimiter) {
      characterOcurrences++;
    }
    if (characterOcurrences == 1) {
      word += sentence[i];
    }
    if (characterOcurrences == 2) {
      break;
    }
  }
  assert(characterOcurrences == 2);
}
