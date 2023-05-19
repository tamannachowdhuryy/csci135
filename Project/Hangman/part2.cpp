/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Dictionary, Project 1B

This will make sure te dictionary that was created can be used by other people 
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {
    ifstream fin(filename);
    string line;
    int index = 0;

    if (!fin.is_open()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
  // while look to get the infomation from tsv file 
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
            g_pos[index] = line.substr(word.length() + 1, pos - word.length() - 2);// used +1 and -2 so it can print out all the words for POS 
            g_definitions[index] = line.substr(pos + 2);
        } else { // used to print the defintion 
            g_pos[index] = "";
            g_definitions[index] = line.substr(word.length() + 2);
        }
        index++;
    }
    g_word_count = index;
}
/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array
*/
int getIndex(string word) {
    for (int i = 0; i < g_word_count; i++) { // put in a for loop to make sure it goes through the loop when the user puts in a word to see if it is in the libary 
        if (g_words[i] == word) { // if it is then the word will return
            return i;
        }
    }
    return -1;
}
/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word){
    int index = getIndex(word); // goes through the for loop to see if the definition exists 
    if (index != -1) {
        return g_definitions[index];
    } else {
        return "NOT_FOUND"; // if not it will return NOT_FOUND
    }
}

/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos) 
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getPOS(string word) {
    int index = getIndex(word); // THIS IS WHERE WE ARE TRYING TO FIND THE POS 
    if (index != -1) { // THIS MEAN THAT THE WORD IN NOT EQUAL 
        return g_pos[index]; // IF IT IS THEN IT WILL RETURN THE POS 
    } else {
        return "NOT_FOUND"; // IF NOT IT WILL PRINT THIS 
    }
}

/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/
int countPrefix(string prefix) {
    int count = 0; // THIS WILL BE THE LENGTH OF THE WORD
    for (int i = 0; i < g_word_count; i++) { // GOES THROUGHT THE FOR LOOP 
        if (g_words[i].substr(0, prefix.length()) == prefix) {
            count++;
        }
    }
    return count; //RETURNS THE COUNT SO THE NUMBER 
}
