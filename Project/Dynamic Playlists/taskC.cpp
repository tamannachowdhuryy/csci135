
/* 
Author: Tamanna Chowdhury
Course: csci-135
Instructor: Genady Marayash
Assignment: Dynamic Playlists, Part C

We basically took our code from Task A and B. We rewrote it using class Songs 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Song {
public:
    string name;
    string artist;
    int duration;
    string genre;
};

int g_capacity = 2; //g_curr_size
int g_size = 0; // g_number_of_songs


Song* g_songs = new Song[g_capacity];

void allocateNew() {
    // Double the capacity of the array
    g_capacity *= 2;
    
    // Create a new dynamically allocated array of the new capacity
    Song* new_songs = new Song[g_capacity];
    
    // Copy the contents of the old array to the new one
    for (int i = 0; i < g_size; i++) {
        new_songs[i] = g_songs[i];
    }
    
    // Delete the old array and update the global pointer to the new array
    delete[] g_songs;
    g_songs = new_songs;
}

//basically what i did was use my old code to rewrite this everything is the same its just we use differnt int form task a and b
void readSongs(string filename) {
    ifstream infile;
    infile.open(filename);

    if (!infile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    // Read each line from the file
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

        // create a Song object with the extracted information
        Song song;
        song.name = song_name;
        song.artist = artist_name;
        song.genre = genre;
        song.duration = duration;

        // add the song information to the global array
        if (g_size == g_capacity) {
            g_capacity *= 2;
            Song* new_songs = new Song[g_capacity];
            for (int i = 0; i < g_size; i++) {
                new_songs[i] = g_songs[i];
            }
            delete[] g_songs;
            g_songs = new_songs;
        }

        g_songs[g_size] = song;
        g_size++;
    }

    infile.close();
}

/*

----------------------------------------TASK B------------------------------------------------------------
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
*/ 

//was having issues with this one so i used what i had for TASK B amd i rewrote it 
Song* getSongsFromDuration(int duration, int& durationsCount, int filter) {
    if (g_size == 0) { // added an if statement
        durationsCount = 0;
        return nullptr;
    }

    // Allocate memory we did this like last time 
    Song* songs = new Song[g_size];
    durationsCount = 0;

    // Iterate over all the songs
    for (int i = 0; i < g_size; i++) {
        if ((filter == 0 && g_songs[i].duration > duration) ||
            (filter == 1 && g_songs[i].duration < duration) ||
            (filter == 2 && g_songs[i].duration == duration) ||
            (filter == -1 && g_songs[i].duration == duration)) { // just added -1 to the filter 
            songs[durationsCount] = g_songs[i];
            durationsCount++;
        }
    }

    // If no songs it will delete and use nullptr and the data can't be accessed
    if (durationsCount == 0) {
        delete[] songs;
        songs = nullptr;
    }

    return songs;
}


Song* getGenreSongs(string genre, int& genreCount) {
    if (g_size == 0) {
        genreCount = 0;
        return nullptr;
    }

    // reusing code from before 
    Song* genreSongs = new Song[g_size];
    genreCount = 0;

    // same thing from the last code 
    for (int i = 0; i < g_size; i++) {
        if (g_songs[i].genre == genre) {
            genreSongs[genreCount] = g_songs[i];
            genreCount++;
        }
    }

    // If no songs it will delete and use nullptr and the data can't be accessed
    if (genreCount == 0) {
        delete[] genreSongs;
        genreSongs = nullptr;
    }

    return genreSongs;
}




string* getUniqueArtists(int& uniqueCount) {
    if (g_size == 0) {
        uniqueCount = 0;
        return nullptr;
    }

    // Using same code from before 
    string* unique_artists = new string[g_size];
    int num_unique_artists = 0;

    // Check each song for unique artist names
    for (int i = 0; i < g_size; i++) {
        bool is_unique = true;
        for (int j = 0; j < num_unique_artists; j++) {
            if (g_songs[i].artist == unique_artists[j]) {
                is_unique = false;
                break;
            }
        }
        if (is_unique) {
            unique_artists[num_unique_artists] = g_songs[i].artist;
            num_unique_artists++;
        }
    }

    // Resize the dynamic array to the actual number of unique artist names
    uniqueCount = num_unique_artists;
    unique_artists = (string*) realloc(unique_artists, num_unique_artists * sizeof(string));

    return unique_artists;
}
string getFavoriteArtist() {
    if (g_size == 0) {
        return "NONE";
    }

    string favorite_artist = g_songs[0].artist;
    int max_count = 1;
    for (int i = 1; i < g_size; i++) {
        int count = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (g_songs[i].artist == g_songs[j].artist) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            favorite_artist = g_songs[i].artist;
        }
    }
    return favorite_artist;
}
/*
int main() {
    // Read songs from file
    readSongs("songs.txt");

    // Print all songs
    for (int i = 0; i < g_size; i++) {
        cout << g_songs[i].name << " by " << g_songs[i].artist
             << " (" << g_songs[i].duration << "s, " << g_songs[i].genre << ")" << endl;
    }

    // Get songs with duration 180 seconds
    int count = 0;
    Song* songs = getSongsFromDuration(180, count, -1);
    if (songs != nullptr) {
        cout << "Songs with duration 180s:" << endl;
        for (int i = 0; i < count; i++) {
            cout << songs[i].name << " by " << songs[i].artist
                 << " (" << songs[i].duration << "s, " << songs[i].genre << ")" << endl;
        }
        delete[] songs;
    }

    // Get songs in the "rock" genre
    int genreCount = 0;
    Song* genreSongs = getGenreSongs("rock", genreCount);
    if (genreSongs != nullptr) {
        cout << "Songs in the rock genre:" << endl;
        for (int i = 0; i < genreCount; i++) {
            cout << genreSongs[i].name << " by " << genreSongs[i].artist
                 << " (" << genreSongs[i].duration << "s)" << endl;
        }
        delete[] genreSongs;
    }

    // Get unique artists
    int uniqueCount = 0;
    string* uniqueArtists = getUniqueArtists(uniqueCount);
    if (uniqueArtists != nullptr) {
        cout << "Unique artists:" << endl;
        for (int i = 0; i < uniqueCount; i++) {
            cout << uniqueArtists[i] << endl;
        }
        delete[] uniqueArtists;
    }

    // Get favorite artist
    cout << "Favorite artist: " << getFavoriteArtist() << endl;

    return 0;
}
*/
