/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 7B
This program will give an unindent.
*/
#include <iostream>

std::string removeLeadingSpaces(std::string line) { // this is to remove the spaces where its not supposed to be in the bad code 
	std::string output;
	bool space = true; // using bool to make a true and false statement 

	for (int i = 0; i < line.length(); i++) { // put in a for loop to get blocks {} 
		if (!isspace(line[i])) {
			space = false; // if there is a space then it will come out false 
		}

		if (!space) { // if that happens them it will output the line 
			output += line[i];

		}
	}

	return output; // then return the output 
}

