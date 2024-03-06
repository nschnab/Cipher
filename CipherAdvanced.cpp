/*
Nolen Schnabel
CPSC 1070: 010
2/27/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "CipherAdvanced.h"
#include "Queue.h"
using namespace std;

bool CipherAdvanced::isWord(string word) //sees if word is word
{

  string line, compareWord;
  bool isWordBool = false, alreadyFound = false, indexWord = false;

  for(int i = 0; (i < ((int)(dict.size()))) && (alreadyFound == false); i++) //loop for all vec values and of the word has not been found
  { 
    compareWord = dict[i];//compares word
    if(compareWord[0] == word[0]) //if the word starts with the same letter
    {
      if(compareWord == word) //if the word is the same
      {
        theWord = compareWord;
        isWordBool = true;
        alreadyFound = true;
      }
      indexWord = true;
    }
    else //else
    {
      if(indexWord)
      {
        alreadyFound = true;
      }
    }
  }
  return isWordBool;
}

void CipherAdvanced::setDict(char first, int wordSize) //sets the vector to the words that start with the codes letter
{
  ifstream file;
  file.open("/usr/share/dict/words"); //open file
  string y;
  dict.clear();

  while(file>>y) //inputs the word
  {
    bool validWordBool = true;

    if((int)(y.length()) == wordSize) // detect if word is of same size
    {
      for(int i = 0; i < (int)(y.length()); i++) //loop for the entire word
      {
        if((y[i] == '\'') || (y[0] != first)) //detects if word has special char
        {
          validWordBool = false;
        }
      }
    }
    else
    {
      validWordBool = false;
    }

    if(validWordBool)
    {
      dict.push_back(y);
    }
  }

  file.close(); //close file
}

void CipherAdvanced::unknownScramble(string word) //driver
{
  Queue q2;
  int size = 1;
  vector<string> wordVec;
  vector<int*> keyVec;
  int wordSize = word.length();
  // int* theKey;
  bool foundWord = false;

  this->arrayPtr = new int[size];
  setCipher(size, arrayPtr);
  char first = word[0];
  first++;
  
  for(int i = 1; i <= 5; i++) //for all key lengths
  {
    if(foundWord == false) //if we already found key
    {
      size = i;
      this->arrayPtr = new int[size];
      if(i == 1) //key size 1
      {
        for(int p = 0; p <= 25; p++)
        {
          if(first == 'a')
          {
            first = 'z';
          }
          else
          {
            first--;
          }

          setDict(first, wordSize);
          // cout<<first<<endl;
          arrayPtr[0] = p;
          setCipher(size, arrayPtr);
          skipWord(word);
          string testWord = decodeMessageA(word);
          if(isWord(testWord))
          {
            keyVec.push_back(getCipher());
            wordVec.push_back(testWord);
            foundWord = true;
          }
        }
      }
      else if(i == 2) //key size 2
      {
        for(int j = 0; j <= 25; j++)
        {
          if(first == 'a')
        {
          first = 'z';
        }
        else
        {
          first--;
        }

        setDict(first, wordSize);
        // cout<<first<<endl;
          arrayPtr[0] = j;
          for(int p = 0; p <= 25; p++)
          {
            arrayPtr[1] = p;
            setCipher(size, arrayPtr);
            skipWord(word);
            string testWord = decodeMessageA(word);
            if(isWord(testWord))
            {
              keyVec.push_back(getCipher());
              wordVec.push_back(testWord);
              foundWord = true;
            }
          }
        }
      }
      else if(i == 3) //key size 3
      {
        for(int i = 0; i <= 25; i++)
        {
          if(first == 'a')
          {
            first = 'z';
          }
          else
          {
            first--;
          }

          setDict(first, wordSize);
          // cout<<first<<endl;
          arrayPtr[0] = i;
          for(int j = 0; j <= 25; j++)
          {
            arrayPtr[1] = j;
            for(int p = 0; p <= 25; p++)
            {
              arrayPtr[2] = p;
              setCipher(size, arrayPtr);
              skipWord(word);
              string testWord = decodeMessageA(word);
              if(isWord(testWord))
              {
                keyVec.push_back(getCipher());
                wordVec.push_back(testWord);
                // foundWord = true;
              }
            }
          }
        }
      }
      else if(i == 4) //key size 4
      {
        for(int o = 0; o <= 25; o++)
        {
        if(first == 'a')
        {
          first = 'z';
        }
        else
        {
          first--;
        }

        setDict(first, wordSize);
        // cout<<first<<endl;
          arrayPtr[0] = o;
          for(int i = 0; i <= 25; i++)
          {
            arrayPtr[1] = i;
            for(int j = 0; j <= 25; j++)
            {
              arrayPtr[2] = j;
              for(int p = 0; p <= 25; p++)
              {
                arrayPtr[3] = p;
                setCipher(size, arrayPtr);
                skipWord(word);
                string testWord = decodeMessageA(word);
                if(isWord(testWord))
                {
                  keyVec.push_back(getCipher());
                  wordVec.push_back(testWord);
                  // foundWord = true;
                }
              }
            }
          }
        }
      }
      else if(i == 5) //key size 5
      {
        for(int t = 0; t <= 25; t++)
        {
          if(first == 'a')
          {
            first = 'z';
          }
          else
          {
            first--;
          }

          setDict(first, wordSize);
          arrayPtr[0] = t;
          // cout<<first<<endl;

          for(int o = 0; o <= 25; o++)
          {
            arrayPtr[1] = o;
            for(int i = 0; i <= 25; i++)
            {
              arrayPtr[2] = i;
              for(int j = 0; j <= 25; j++)
              {
                arrayPtr[3] = j;
                for(int p = 0; p <= 25; p++)
                {
                  arrayPtr[4] = p;
                  setCipher(size, arrayPtr);
                  skipWord(word);
                  string testWord = decodeMessageA(word);
                  if(isWord(testWord))
                  {
                    keyVec.push_back(getCipher());
                    wordVec.push_back(testWord);
                    // foundWord = true;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  
  cout<<endl;
  cout<<endl;
  if((int)(wordVec.size()) >= 1) //if word exists
  {
    for(int i = 0; i < (int)(wordVec.size()); i++)
    {
      for(int j = 0; j < (int)(wordVec.size()); j++) //remove duplicate words
      {
        if((wordVec[i] == wordVec[j]) && (i != j))
        {
          string temp = wordVec[j];
          wordVec[j] = wordVec[(int)(wordVec.size()) - 1]; //swap word to back
          wordVec[(int)(wordVec.size()) - 1] = temp;
          wordVec.pop_back(); //pop back vector

          int * temp1 = keyVec[j];
          keyVec[j] = keyVec[(int)(keyVec.size()) - 1]; //swap key to back
          keyVec[(int)(keyVec.size()) - 1] = temp1;
          keyVec.pop_back(); //pop back vec
          delete temp1;
        }
      }
    }
    cout<<"Word is: "<<endl;;
    for(int i = 0; i < (int)(wordVec.size()); i++) //print out words
    {
      cout<<wordVec[i]<<", ";
      int * keyPtr1 = keyVec[i];
      for(int j = 0; j < 5; j++)
      {
        cout<<keyPtr1[j]<<", ";
      }
    cout<<endl;
    }
    cout<<endl;
  }
  else //eles no words exist
  {
    cout<<"NO POSSIBILITIES EXIST"<<endl;
  }
  // cout<<"Done!"<<endl;
}

void CipherAdvanced::skipWord(string word) //skips word if unusable combo
{
  if((word[0] == 'q') && (word[1] != 'u')) // detect if 3 vowels in a row
  {
    arrayPtr[1]++;
  }
  if(word[(int)(word.length()) - 1] == 'q')
  {
    arrayPtr[((int)(word.length()) - 1) % 5]++;
  }
  if((word[0] == 'o') && (word[1] == 'e'))
  {
    arrayPtr[1]++;
  } 
  if((word[0] == 'e') && (word[1] == 'o'))
  {
    arrayPtr[1]++;
  }
  if((word[0] == 'y') && (word[1] > 117))
  {
    arrayPtr[1]++;
  }
}

string CipherAdvanced::decodeMessageA(string in) //decodes message
{
    string out = "";

    for(int i = 0; i < (int)(in.length()); i++)
    {
        if((in[i] == ' ') || (in[i] == '!'))
        {

        }
        else
        {
            out += in[i];
        }
    }

    int num = 0;
    for(int i = 0; i < (int)(out.length()); i++) //decodes the message
    {
            q.dequeue(num);
            q.enqueue(num);
            // out[i] -= num;
            int num2 = abs(num);
            for(int j = 0; j < num2; j++)
            {
                if (num > 0)
                {
                    if(out[i] == 'a')
                    {
                        // cout<<out[i];
                        out[i] = 'z';
                    }
                    else
                    {
                        --out[i];
                    }
                }
                else if(num < 0)
                {
                    if(out[i] == 'z')
                    {
                        // cout<<out[i];
                        out[i] = 'a';
                    }
                    else
                    {
                        ++out[i];
                    }
                }
            }
    }
    // cout<<"Decoded: "<<out<<endl; //prints post-decoded message
    // cout<<endl;
    q.enqueue(*keyPtr);
    return out;
}

//--------------------------------------------------------

void CipherAdvanced::testKey(int * keyThingy, string word1)
{
  // decodeMessageA()
}