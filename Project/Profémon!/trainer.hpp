
/* 

Author: Tamanna Chowdhury
Course: csci-135
Instructor: Genady Marayash
Assignment: Project 3 Part B
*/
#ifndef TRAINER_HPP
#define TRAINER_HPP

#include <iostream>
#include <vector>
#include <string> 
#include "profemon.hpp"
#include "skill.hpp"

/*
Use protected instead of private
- A vector of profémons which represents a profedéx
- A profémon array of size 3 which represents the trainer's current team
- A pointer to a profémon which is currently selected from the team
*/
class Trainer {
    protected:
        vector<Profemon> profedex;
        Profemon team[3];
        Profemon* selected;
    public:
        Trainer();
        Trainer(std::vector<Profemon> profemons);
        bool contains(std::string name);
        bool addProfemon(Profemon profemon);
        bool removeProfemon(std::string name);
        void setTeamMember(int slot, std::string name);
        bool chooseProfemon(int slot);
        Profemon getCurrent();
        void printProfedex();
        void printTeam();

};

#endif // TRAINER_HPP
