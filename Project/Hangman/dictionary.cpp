/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Dictionary, Project 1A

This will make a dictionary Array
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {
    ifstream infile(filename);
    string line;
    int index = 0;

    if (infile) {
        while (getline(infile, line) && index < g_MAX_WORDS) {
            stringstream ss(line);
            string word;
            getline(ss, word, ' ');
            if (word == "WORD") {
                g_words[index] = "WORD";
                g_definitions[index] = "DEFINITION";
                g_pos[index] = "POS";
                index++;
                continue;
            }
            g_words[index] = word;
            getline(ss, word, ':');
            g_pos[index] = word;
            getline(ss, word);
            g_definitions[index] = word.substr(1);
            index++;
        }
        g_word_count = index;
    }
}
/*
int main() {
    readWords("dictionary.txt");

    cout << "g_MAX_WORDS: " << g_MAX_WORDS << endl;
    cout << "g_word_count: " << g_word_count << endl;
    cout << "g_words: [\"" << g_words[0] << "\"";
    for (int i = 1; i < g_word_count; i++) {
        cout << ", \"" << g_words[i] << "\"";
    }
    cout << "]" << endl;

    cout << "g_pos: [\"" << g_pos[0] << "\"";
    for (int i = 1; i < g_word_count; i++) {
        cout << ", \"" << g_pos[i] << "\"";
    }
    cout << "]" << endl;

    cout << "g_definitions: [\n    \"" << g_definitions[0] << "\",\n";
    for (int i = 1; i < g_word_count; i++) {
        cout << "    \"" << g_definitions[i] << "\",\n";
    }
    cout << "]" << endl;

    return 0;
}
*/
