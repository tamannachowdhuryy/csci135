/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Dictionary, Project 1A

This will make a dictionary Array
*/
#include <iostream>
#include <fstream>
#include <cstdlib> // defines a collection of functions
#include <string> // stores letter or characters 

using namespace std;

// code from the website
const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {
    ifstream fin(filename); //calls the file 
    string line;
    int index = 0;

    if (!fin.is_open()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
  // while loop to get the infomation from tsv file 
    while (getline(fin, line) && index < g_MAX_WORDS) {
        string word;
        string::size_type pos = 0;
        if ((pos = line.find(' ')) != string::npos) {
            word = line.substr(0, pos);
        } else {
            word = line;
        }
      // decleared an array to make get the file to read and get the information need for the dictionary 
        if (word == "WORD") {
            g_words[index] = "WORD";
            g_definitions[index] = "DEFINITION";
            g_pos[index] = "POS";
            index++;
            continue;
        }
      //find info from the tsv file 
        g_words[index] = word;
        if ((pos = line.find(':', pos+1)) != string::npos) {
            g_pos[index] = line.substr(word.length() + 1, pos - word.length() - 2);// used +1 and -2 so it can print out all the words for POS so it will print out NOUN instead of OUN  
            g_definitions[index] = line.substr(pos + 2); // this is for def so it can print out all the words 
        } else { // used to print the defintion 
            g_pos[index] = ""; //empty string so it can insert word
            g_definitions[index] = line.substr(word.length() + 2); // prints out the length the word for the tsv is supposed to be 
        }
        index++;
    }
    g_word_count = index;
}

//this is the main function where i can see if it prints out what gradescope 
/*
int main() {
    readWords("dictionary.tsv");

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

    cout << "g_definitions: [\n    \""      << g_definitions[0] << "\",\n";
    for (int i = 1; i < g_word_count; i++) {
        cout << "    \"" << g_definitions[i] << "\",\n";
    }
    cout << "]" << endl;

    return 0;
}
*/


