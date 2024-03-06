/*
Nolen Schnabel
CPSC 1070: 010
2/27/2023
*/

#include <iostream>
#include <string>
#include "Cipher.h"
using namespace std;

Cipher::Cipher() //constructor
{
    this->keyPtr = new int[size]{1,2,3,4}; //default key
    for(int i = 0; i < size; i++) //loop for all key
    {
        q.enqueue(keyPtr[i]); //queue key
    }
}

void Cipher::setCipher(int size, int key[]) //sets cipher
{
    this->size = size; //sets new size
    q.clear(); //clears old queue
    this->keyPtr = new int[size]; //sets new key
    for(int i = 0; i < size; i++) //queues the new key
    {
        keyPtr[i] = key[i];
        q.enqueue(keyPtr[i]);
    }
}

int* Cipher::getCipher() //returns Cipher
{
    return keyPtr;
}

string Cipher::encodeMessage(string in) // encodes the message using cipher key
{
    int i;
    cout<<"Key: [";
    for(i = 0; i < (q.getQueueSize() - 1); i++) //prints key values
    {
        cout<<keyPtr[i]<<", ";
    }
    cout<<keyPtr[i]<<"]"<<endl;

    cout<<"Encoding: "<<in<<endl; //print pre-coded message

    string out = "";

    for(int i = 0; i < (int)(in.length()); i++)
    {
        if((in[i] == 32) || (in[i] == '!')  || (in[i] == '@')  || (in[i] == '#')  || (in[i] == '$')  || (in[i] == '%')  || (in[i] == '^')  || (in[i] == '&')  || (in[i] == '*')  || (in[i] == '(')  || (in[i] == ')')  || (in[i] == ',')  || (in[i] == '.')  || (in[i] == '/') || (in[i] == '[') || (in[i] == ']') || (in[i] == '{') || (in[i] == '|') || (in[i] == '\\') || (in[i] == ':') || (in[i] == ';') || (in[i] == '<') || (in[i] == '>') || (in[i] == '?') || (in[i] == '`') || (in[i] == '~') || (in[i] == '-') || (in[i] == '_') || (in[i] == '+') || (in[i] == '=') || (in[i] == '1') || (in[i] == '2') || (in[i] == '3') || (in[i] == '4') || (in[i] == '5') || (in[i] == '6') || (in[i] == '7') || (in[i] == '8') || (in[i] == '9') || (in[i] == '0'))
        {

        }
        else
        {
            out += in[i];
        }
    }

    int num = 0;
    for(int i = 0; i < (int)(out.length()); i++) //encodes the message
    {
            out[i] = tolower(out[i]);
            q.dequeue(num);
            q.enqueue(num);
	    // cout<<num;

        int num2 = abs(num);
            // out[i] += num;
            for(int j = 0; j < num2; j++)
            {
                if (num < 0)
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
                else if(num > 0)
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
    cout<<"Encoded: "<<out<<endl; //prints post-coded message
    cout<<endl;
    setCipher(size, keyPtr);
    return out;
}

string Cipher::decodeMessage(string in) //decodes message
{
    int i;
    cout<<"Key: [";
    for(i = 0; i < (q.getQueueSize() - 1); i++) //prints key values
    {
        cout<<keyPtr[i]<<", ";
    }
    cout<<keyPtr[i]<<"]"<<endl;

    cout<<"Decoding: "<<in<<endl; //print pre-decoded message

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
    cout<<"Decoded: "<<out<<endl; //prints post-decoded message
    cout<<endl;
    q.enqueue(*keyPtr);
    return out;
}
