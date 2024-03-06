/*
Nolen Schnabel
CPSC 1070: 010
2/27/2023
*/

#ifndef CIPHERADVANCED_H
#define CIPHERADVANCED_H

#include <string>
#include <vector>
#include "Cipher.h"
using namespace std;

class CipherAdvanced : public Cipher
{
public:
  void unknownScramble(string word);
  bool isWord(string word);
  void skipWord(string word);
  string decodeMessageA(string in);
  void setDict(char, int);
  void testKey(int*, string);
  //vector<string> posiVec;
  //string theWord;
};
#endif
