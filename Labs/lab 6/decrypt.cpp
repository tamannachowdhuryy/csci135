/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab6D
This program will decrypt the cipher word withe the key word and shift that was given.
*/


#include <iostream>
#include "decrypt.h"
#include "caesar.h"
#include "funcs.h"


// this is part D
std::string decryptCaesar(std::string ciphertext, int rshift) {
    std::string result;
    for(int i = 0;i < ciphertext.length(); i++){ // this will decrpt the word and use the word that was given to print the new word out 
        result+= shiftChar(ciphertext[i], rshift * -1);  // it will use the number it was given to then find the orginal word
    }
    return result;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){ //this will take a key word 
    std::string result;
    char letters[keyword.length()];
    for(int i = 0; i < keyword.length(); i++){ // then go through a for loop
        letters[i] = keyword[i];
    }
    int count = -1;
    for(int i = 0; i < ciphertext.length();i++){
        if(isalpha(ciphertext[i])){
            count++;
            result += shiftChar(ciphertext[i], (((int)letters[count % keyword.length()] - 97) * -1)); // going through the list to print out the work after decryting it 
        } else{
            result += ciphertext[i];
        }
    }
    return result; //print the result out 
}
