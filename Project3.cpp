/*
Nolen Schnabel
CPSC 1070: 010
2/27/2023
*/

#include <string>
#include <iostream>
#include "Queue.h"
#include "Cipher.h"
#include "CipherAdvanced.h"
using namespace std;

int main(void)
{
    int tempKey[5] = {5, 6, 9, 4, 3};
    Cipher c;
    // for (int i = 0; i <= 103; i++)
    // {
    //     tempKey[i] = i;
    // }
    c.setCipher(5, tempKey);
    string message = "bowling";
    string enCode = c.encodeMessage(message);
    // cout<<message<<endl;
    // cout<<enCode<<endl;
    CipherAdvanced p;
    enCode = "yqujuz";

    c.decodeMessage(enCode);

    p.unknownScramble(enCode);
    // p.setDict('p');
    // cout<<endl;
    // p.setDict('q');
    return 0;
}
