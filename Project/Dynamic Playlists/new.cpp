
/* 
Author: Tamanna Chowdhury
Course: csci-135
Instructor: Genady Marayash
Assignment: Dynamic Playlists, Part A
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

using namespace std;

int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

void allocateNew() {
    // double the size of the arrays
    int new_size = g_curr_size * 2;
    string *new_song_names = new string[new_size];
    string *new_artist_names = new string[new_size];
    int *new_song_durations = new int[new_size];
    string *new_genres = new string[new_size];

    // copy the old arrays to the new arrays
    for (int i = 0; i < g_number_of_songs; i++) {
        new_song_names[i] = g_song_names[i];
        new_artist_names[i] = g_artist_names[i];
        new_song_durations[i] = g_song_durations[i];
        new_genres[i] = g_genres[i];
    }

    // free the memory occupied by the old arrays
    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;

    // point the old arrays to the new arrays
    g_song_names = new_song_names;
    g_artist_names = new_artist_names;
    g_song_durations = new_song_durations;
    g_genres = new_genres;

    g_curr_size = new_size;
}

void readSongs(string filename) {
    ifstream infile;
    infile.open(filename);

    if (!infile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        // skip empty lines
        if (line.empty()) {
            continue;
        }

        // remove the newline character from the end of the line
        line = line.substr(0, line.length() - 1);

        // extract song information from the line
        string song_name = line.substr(0, line.find(":"));
        string artist_name = line.substr(line.find(":") + 1, line.find("-") - line.find(":") - 1);
        string genre = line.substr(line.find("-") + 1, line.find_last_of("-") - line.find("-") - 1);
        int duration = stoi(line.substr(line.find_last_of("-") + 1, line.find("mins") - line.find_last_of("-") - 1));

        // add the song information to the global arrays
        if (g_number_of_songs == g_curr_size) {
            allocateNew();
        }

        g_song_names[g_number_of_songs] = song_name;
        g_artist_names[g_number_of_songs] = artist_name;
        g_genres[g_number_of_songs] = genre;
        g_song_durations[g_number_of_songs] = duration;

        g_number_of_songs++;
    }

    infile.close();
}



// TASK 2
string * getGenreSongs(string genre, int &genreCount){
    string *genreSong = new string[g_number_of_songs]; // making a new string and pointer to store data 
    int count = 0; // starting out with no songs 

    for(int i = 0; i < g_number_of_songs; i++){ // for loop to ensure we get the genre songs 
        if(g_genres[i] == genre){ 
            genreSong[count] = g_song_names[i]; // this is saying that when it is being counted it is qualing to the number of songs
            count++; // adding one
        }
    }
    genreCount = count; // this is telling you that the new string is equal to the num
    return genreSong; // give the value

}

string * getSongsFromDuration(int duration, int& durationsCount, int filter) { // pointer is the &
    // Create a dynamic array to store the matching song names
    string *songFromDuration = new string[g_number_of_songs];
    
    // Initialize durationsCount to 0
    int s_duration = 0;
   
    // Iterate over each song
    for (int i = 0; i < g_number_of_songs; i++) { // repating code 
     //Check if the song duration matches the filter
        if ((filter == 0 && g_song_durations[i] > duration)){
               songFromDuration[s_duration] = g_song_names[i];
               s_duration++;
        }
        else if ((filter == 1 && g_song_durations[i] < duration) ||
                 (filter == 2 && g_song_durations[i] == duration)) {
                 songFromDuration[s_duration] = g_song_names[i];
                 s_duration++;
                 }
    }
    durationsCount = s_duration; // we are setting it equal to the s_duration

    return songFromDuration; // the pointer we made before the data will be stored in here
}

string * getUniqueArtists(int& uniqueCount) {
    // Create an array to store unique artist names
    string* uniqueArtists = new string[g_number_of_songs];
    int uniqueIndex = 0;

    // Loop through all the artists and add unique ones to the array
    for (int i = 0; i < g_number_of_songs; i++) {
        bool isUnique = true;
        for (int j = 0; j < uniqueIndex; j++) {
            if (g_artist_names[i] == uniqueArtists[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueArtists[uniqueIndex] = g_artist_names[i];
            uniqueIndex++;
        }
    }

    // Set the output parameter to the number of unique artists found
    uniqueCount = uniqueIndex;

    // Return the array of unique artist names
    return uniqueArtists;
}


string getFavoriteArtist() {
    if (g_number_of_songs == 0) {
        return "NONE";
    }

    string favorite_artist = g_artist_names[0];
    int max_count = 1;
    for (int i = 1; i < g_number_of_songs; i++) {
        int count = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (g_artist_names[i] == g_artist_names[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            favorite_artist = g_artist_names[i];
        }
    }
    return favorite_artist;
}



























