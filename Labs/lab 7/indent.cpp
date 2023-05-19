/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 7A
This will make an indent in the bad_code.cpp errors
*/
#include <iostream>
#include <iostream>
#include <fstream>
#include "unindent.h"

int countChar(std::string line, char c) {
	int count = 0;
	
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == c) {
			count++;
		}
	}

	return count;
}


std::string indentation(std::ifstream& Bcode) { // this code will make indentation to the bad-code.cpp file
	std::string line, output;
	int count = 0;

	while (std::getline(Bcode, line)) {
		line = removeLeadingSpaces(line); //put in a while loop to read the file

		if (line[0] == '}') { // when it see } it will subtract by one and put it in the correct place for the bad code
			count--;
		}

		for (int i = 0; i < count; i++) { // for loop to make sure the char is put in place
			output += '\t';
		}

		output += line + '\n';
		count += countChar(line, '{');

	}

	Bcode.close(); // this will close the bad file from the main file

	return output;
}
