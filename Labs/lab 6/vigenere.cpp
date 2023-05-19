/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab6C
This program will take a word and use a keyword to make a new word that is ciphered text.
*/

#include <iostream>
#include <string>
#include <cctype>
#include "vigenere.h"
#include "funcs.h"

// part C : this is implementing vigenere to encryt 
std::string encryptVigenere(std::string plaintext, std::string keyword) {
    std::string result; // takes the word
    for (int i = 0, j = 0; i < plaintext.size(); ++i) { //puts it is a for loop
        char current = plaintext[i];
        if (isalpha(current)) {
            char key = keyword[j];
            key = tolower(key) - 'a'; // then starts to subtract from the given keyword
            char shifted = ((current + key - 'a') % 26) + 'a';
            result += shifted;
            j = (j + 1) % keyword.size(); //finding the word and if they fo 
        } else {
            result += current;
        }
    }
    return result; // it prints it out 
}

