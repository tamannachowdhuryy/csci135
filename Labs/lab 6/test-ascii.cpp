/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab6A
This program asks the user to input a line of text (which may possibly include spaces). Then, it reports all the characters from the input line together with their ASCII codes
*/

#include <iostream>
#include <string>

int main(){
    std::string input = "Cat :3 Dog";
    for(int x = 0; x < input.length(); x++){ // if statement so it can list out the number 
        std::cout << input[x] << " " << (int)(input[x]) << std::endl; // will be inputting a empty string
    }

    return 0;
} 
