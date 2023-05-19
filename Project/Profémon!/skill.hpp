/* 

Author: Tamanna Chowdhury
Course: csci-135
Instructor: Genady Marayash
Assignment: Project 3
*/
#ifndef SKILL_HPP
#define SKILL_HPP
#include <iostream> 
#include <string>
using namespace std;

/* - The name of the skill
- The description of the skill
- The total number of times the skill can be used 
- An integer that represents the specialty of the skill (0, 1 or 2)
*/
class Skill {
private:
//Variables 
    std::string name;
    std::string description; 
    int totalUses; // has numbers
    int specialty; // has numbers
    
public:
    // Constructors 
    Skill();
    Skill(std::string name, std::string description, int specialty, int uses);
    std::string getName();
    
    //Accessors
    //int getName;
    std::string getDescription();
    int getTotalUses();
    int getSpecialty();
    //Mutators
    void setName(std::string name);
    void setDescription(std::string description);
    void setTotalUses(int uses);
    bool setSpecialty(int specialty);
    
   
};

#endif

