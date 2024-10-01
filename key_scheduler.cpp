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
    //Import 64-bit key
    // permChoice1 = 56 bits of key
    //C = 28 bits & D = 28 bits (half & half)
    // for (int i = 0; i < 16; i++){
        // Left shift C and left shift D
        // permChoice2 = C+D in 48 bits
        // add permChoice2 to sub_keys
    
    return sub_keys;
}