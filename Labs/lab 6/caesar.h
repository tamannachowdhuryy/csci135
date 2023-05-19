
#pragma once
#include <vector>

std::string encryptCaesar(std::string plaintext, int rshift);
std::string decryptCaesar(std::string ciphertext, int rshift);
char shiftChar(char c, int rshift);
std::string solve(std::string encrypted_string);
std::vector<double> countFrequencies(std::string encrypted_string);
