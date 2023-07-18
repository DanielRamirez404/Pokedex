#ifndef USER_STRING
#define USER_STRING
#include <string>

std::string uppercase(std::string myString);
std::string getWordInSentence(std::string sentence, int wordNumber);
std::string getWordByCharLimits(std::string sentence, char lowerLimit, char upperLimit);
void loopWordByDifferentCharLimits(std::string& word, std::string sentence, char lowerLimit, char upperLimit);
void loopWordBySameCharLimits(std::string& word, std::string sentence, char delimiter);

#endif
