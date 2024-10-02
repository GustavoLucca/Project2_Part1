#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string shift_left(string sub_key, int shiftNum){
    for (int i = 0; i < shiftNum; ++i){ //Shifts through every bit, doing shiftNum amount of loops.
        char firstBit = sub_key[0]; //Register what the first bit is.
        sub_key = sub_key.substr(1) + firstBit; // Move every bit left one spot and add the first bit at the end.
    }
    
    return sub_key;
} 

vector<string> key_gen(string key){
    vector<string> sub_keys;
    //First, we find the mappings for the bits that will be processed in Permuted Choice 1 and then successively in Permuted Choice 2.
    vector<int> PCone = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    vector<int> PCtwo = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    //Then, we apply PCone to the entire key.
    string permChoice1;
    for (int i = 0; i < 56; i++) {
        permChoice1 += key[PCone[i] - 1];
    }
    //Then, we split the new 56 bit key into two.
    string C = permChoice1.substr(0, 28);  // First 28 bits
    string D = permChoice1.substr(28, 28); // Next 28 bits
    //Now, we generate the subkeys and apply PCtwo to all of them.
    for (int i = 0; i < 16; i++) {
        if (i == 0 || i == 1 || i == 8 || i == 15) {
            C = shift_left(C, 1);
            D = shift_left(D, 1);
        } else {
            C = shift_left(C, 2);
            D = shift_left(D, 2);
        }
        string CD = C + D;
        //Now that the separate keys have been shifted according to the schedule and joined back together, we apply Permuted Choice 2 to it and add it to the sub_keys vector.
        string permChoice2;
        for (int j = 0; j < 48; j++) {
            permChoice2 += CD[PCtwo[j] - 1];
        }
        sub_keys.push_back(permChoice2);
    }
    return sub_keys;
}