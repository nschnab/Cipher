/*
Nolen Schnabel
CPSC 1070: 010
2/27/2023
*/

#ifndef CIPHER_H
#define CIPHER_H
#include <string>
#include <vector>
#include "Queue.h"
// #include "CipherAdvanced.h"

using namespace std;

class Cipher
{
    public:
Cipher();
void setCipher(int, int[]);
int* getCipher();
string encodeMessage(string in);
string decodeMessage(string in);
void setKey2(const int[], int);
    protected:
  string theWord;
  int * arrayPtr;
  vector<string> dict;
  Queue q;
  int * keyPtr;
  int size = 4;
  int key2[];
};
#endif
