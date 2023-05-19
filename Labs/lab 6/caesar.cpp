/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab6B
This program is used to make a shift with the number that was given and the word will change.
*/
#include <iostream>
#include "caesar.h"
#include "funcs.h"
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;
//this is part B which is showing how to shift the word on what number is given 
char shiftChar(char c, int rshift){
    int shiftedc = c + rshift;
    if(c >= 65 && c <= 90){ // these are all the CAPITIAL LETTERS
        if(shiftedc < 65){
            return shiftedc + 26;
        }
        if(shiftedc > 90){
            return shiftedc - 26;
        }
        return shiftedc;
    }
    if(c >= 97 && c <= 122){ /// these are for the lower case letters
        if(shiftedc < 97){
            return shiftedc + 26;
        }
        if(shiftedc > 122){
            return shiftedc - 26;
        }
        return shiftedc;
    }
    return c;
}
//the word will go through a for loop and print the word out after the shift 
std::string encryptCaesar(std::string plaintext, int rshift){
    std::string result;
    for (int i = 0; i < plaintext.length();i++){
        result += shiftChar(plaintext[i],rshift);
    }
    return result;
}

vector<double> countFrequencies(string encrypted_string){

    vector<double> frequencies(26,0.0); // ENGLISH ALAPBETS 

    for(int i = 0; i < encrypted_string.length(); i++){
        if(isalpha(encrypted_string[i])){
            int index = 0;

            if(isupper(encrypted_string[i]))
                index = (int)(encrypted_string[i]) - 65; /UPPERCASE LETTERS
            else
                index = (int)(encrypted_string[i]) - 97; //LOWER CASE LETTERS 

            frequencies[index] += 1;
        }
    }
    //calculate frequencies
    for(int i = 0; i < 26; i++)
        frequencies[i] = frequencies[i] / encrypted_string.length();

    return frequencies;
}
//EXTRA LAB
std::string solve(std::string encrypted_string){
    std::vector<double> english_frequencies{.084966,.020720,.045388,.033844,.111607,.018121,.024705,.030034, .075448,.001965,.011016,.054893,.030129,.066544,.071635,.031671,.001962,.075809,.057351,.069509,.036308,.010074,.012899,.002902,.017779,.002902}; //Each element of the vector represents the frequency of a letter in the English alphabet
    std::vector<double> frequencies(26, 0.0);

    double closest = 0.0; 
    std::string output = "";
    std::string rotated = ""; 
    double currFreq = 0.0;

    for(int i = 0 ; i < 26; i++){
        rotated = decryptCaesar(encrypted_string, i);
        frequencies = countFrequencies(rotated); //THIS WILL ROTATE THE FREQUENCY 
        double distance = 0.0;

        for(int j = 0; j < 26; j++)
            distance += pow((frequencies[j] - english_frequencies[j]) , 2); //TAKING THE NUMBERS FROM ABOVE AN SUBTRACTING IT SO WHEN WE NEED TO MAKE A CHANGE IN THE SENTECE IT WILL DECODE IT 

// Calculate the distance between the frequencies and the expected English frequencies
        for (int i = 0; i < 26; i++) {
            distance += std::pow(frequencies[i] / encrypted_string.length() - english_frequencies[i], 2);
        }

        if(closest == 0.0){
            closest = distance;
            output = rotated;
        }
        if(distance < closest){
            closest = distance;
            output = rotated; //PRINTS OUT THE OUTPUT 
        }

    }

    return output;
}


