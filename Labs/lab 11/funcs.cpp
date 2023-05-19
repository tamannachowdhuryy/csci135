/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Mike Zamansky 
Assignment: Classes and Programming a Social Network; Lab 11

This assigment we learnt to member variables, functions and constructors and destructors 
*/

//TASK B
#include <iostream> 
#include "funcs.h"
using namespace std;


Network::Network(){ //this will be the profile task B
	numUsers = 0; // the amount of users in the data
	for(int i = 0; i < MAX_USERS; i++) { //for loop for the max users 
		for(int j = 0; j < MAX_USERS; j++) { // this will help find the following 
			following[i][j] = false;
		}
	}
}

int Network::findID(string usrn) { //this will find the ID of the users that have been inputted into the data
	for(int i = 0; i < numUsers; i++){ //put in a for loop to get the users name in the User data
		if(profiles[i].getUsername() == usrn) {
			return i;
		}
	}
	return -1; //will return -1 as the instruction has said 
}

bool Network::addUser(std::string usrn, std::string dspn){ // this will add new users into the data
    if (numUsers == MAX_USERS){ 
        return false;
    }
    for (int i = 0; i < usrn.size(); i++){ // will give the size
        if (!isalnum(usrn[i])){ 
            return false;
        }
    }
    if (findID(usrn) != -1) {
        return false;
    }

    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
}

bool Network::follow(std::string usrn1, std::string usrn2) { // this will show the newtowrk following the person has 
	int userID1 = findID(usrn1);
    int userID2 = findID(usrn2);

    if(userID1 != -1 && userID2 != -1) {
		following[userID1][userID2] = true;
		return true;
	}
	return false;
}

void Network::printDot() {
	std::cout << "digraph {" << std::endl;
	for(int i = 0; i < numUsers; i++) {
		std::cout << "  \"@" << profiles[i].getUsername() << "\"" << std::endl;
	}

	std::cout << std::endl;

	for(int i = 0; i < numUsers; i++){
		for(int j = 0; j < numUsers; j++){
			if(following[i][j]){
				std::cout << "\t\"@" << profiles[i].getUsername() << "\"" << " -> ";
                std::cout << "\"@" << profiles[j].getUsername() << "\""<< std::endl;
			}
		}
	}
	std::cout << "}" << std::endl;
}
