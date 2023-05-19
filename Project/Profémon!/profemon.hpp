
/* 

Author: Tamanna Chowdhury
Course: csci-135
Instructor: Genady Marayash
Assignment: Project 3
*/
#ifndef PROFEMON_HPP
#define PROFEMON_HPP
#include "skill.hpp"
#include <iostream>
#include <string>

enum Specialty { ML, SOFTWARE, HARDWARE };

class Skill;

class Profemon {
private:
    std::string name;
    int level;
    int required_exp;
    int current_exp;
    double max_health;
    Specialty specialty;
    Skill skills[3];

public:
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);

    std::string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();

    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
};

#endif  // PROFEMON_HPP
