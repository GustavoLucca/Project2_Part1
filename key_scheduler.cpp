#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string shift_left(string sub_key){
    char firstBit = sub_key[0];
    sub_key = sub_key.substr(1) + firstBit;
    return sub_key;
} 

vector<string> key_gen(string key){
    // we can use key_utils.h
    // for PC1 and PC2
    
    vector<string> sub_keys;
    int shiftsLookup[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    
    string permutatedKey = "";
    for (int i = 0; i < 56; i++) {
        // PC1
        permutatedKey += key[PC1[i] - 1];
    }

    string leftHalf = permutatedKey.substr(0, 28);
    string rightHalf = permutatedKey.substr(28, 28);
    string combinedKey;
    string subKey;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < shiftsLookup[i]; j++) {
            leftHalf = shift_left(leftHalf);
            rightHalf = shift_left(rightHalf);
        }
        combinedKey = leftHalf + rightHalf;
        subKey = "";
        for (int j = 0; j < 48; j++) {
            // PC2
            subKey += combinedKey[PC2[j] - 1];
        }
        sub_keys.push_back(subKey);
    } 

    return sub_keys;
}
