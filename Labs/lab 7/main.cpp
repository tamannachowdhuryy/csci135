#include <iostream>
#include <fstream>
#include "unindent.h"
#include "indent.h"

int main() {

	//Task A
	std::string line = "       int x = 1;  ";
	std::cout << '"' << line << '"' << std::endl << '"' << removeLeadingSpaces(line) << '"' << std::endl;


	//Task B
	//Read bad-code.cpp
	std::string output;
	std::ifstream badF("bad-code.cpp");
	if (badF.fail()) {
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}

	// fix bad-code.cpp
	output = indentation(badF);
	std::cout << "\nFixed bad-code.cpp:\n" << output << std::endl;


	return 0;
}
