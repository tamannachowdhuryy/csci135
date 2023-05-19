/* 

Author: Tamanna Chowdhury
Course: csci-135
Instructor: Genady Marayash
Assignment: Project 3
*/
#include <iostream>
#include <string>
#include "skill.hpp" 
#include "profemon.hpp"


using namespace std;

/*
    @post       :   Initializes the name of the Profémon
                    as "Undefined"
*/  
Profemon::Profemon() {
    name = "Undefined";
}

  
/*
    @post       :   Initializes the name, max health 
                    and specialty as the corresponding
                    parameters. Set the required 
                    experience equal to 50. 
                    Initializes the current experience
                    and level as 0
*/  
Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    this->name = name;
    level = 0;
    required_exp = 50;
    current_exp = 0;
    this->max_health = max_health;
    this->specialty = specialty;
    /*
    for (int i = 0; i < 3; i++) {
        Skill s{"Undefined", 0, "Undefined"};
        skills[i] = s;
    }
    */
}
/*
    @return     :   name of the Profémon
*/
std::string Profemon::getName() {
    return name;
}
/*
    @return     :   specialty of the Profémon
*/
Specialty Profemon::getSpecialty() {
    return specialty;
}

/*
    @return     :   level of the Profémon
*/
int Profemon::getLevel() {
    return level;
}
/*
    @return     :   maximum health of the Profémon
*/
double Profemon::getMaxHealth() {
    return max_health;
}
/*
    @post       :   set the name of the Profémon 
                    equal to the given parameter
*/


void Profemon::setName(std::string name) {
    this->name = name;
}
/*
    @param      :   experience points earned by the Profémon 
    @post       :   Increase the Profémon's level based on
                    the given 'exp'. The Profémon will level
                    up if it reaches the required experience.
                    Depending on the Profémon's specialty,
                    the required experience goes up by a certain
                    amount everytime the Profémon levels up.
                    'ML' required experience goes up by 10,
                    'SOFTWARE' goes up by 15, and 'HARDWARE'
                    goes up by 20. Make sure to update the
                    required, current experience and level
                    private data members accordingly. The given 
                    'exp' can result in the Profémon leveling 
                    up multiple times
  
  For example   :   starting at lvl 0, calling 'levelUp(115)'
                    on different types of Profémon would result
                    in the following:

                    ML:
                      - new level: 2
                      - current exp: 5
                      - required exp: 70

                    SOFTWARE:
                      - new level: 2
                      - current exp: 0
                      - required exp: 80

                    HARDWARE:
                      - new level: 1
                      - current exp: 65
                      - required exp: 70

                    As stated above, each specialty has 
                    a different speed of leveling up


*/
void Profemon::levelUp(int exp) {
    current_exp += exp;
    while (current_exp >= required_exp) {
        level++;
        current_exp -= required_exp;
        switch (specialty) {
            case ML:
                required_exp += 10;
                break;
            case SOFTWARE:
                required_exp += 15;
                break;
            case HARDWARE:
                required_exp += 20;
                break;
            default:
                break;
        }
    }
}


/*
    @param      :   the skill slot or index
    @param      :   the new skill to be learned 
    @return     :   return 'true' if the skill has been successfully 
                    learned. Return 'false' if 'slot' parameters is 
                    not within the valid range(0,1,2) or the 
                    specialty of the 'skill' does not match 
                    the specialty of the Profémon 
    @post       :   if the given slot is valid(0,1,2) and the
                    skill specialty matched with the Profémon,
                    add the 'skill' to the 'slot' index of the
                    learned skills array                



*/

bool Profemon::learnSkill(int slot, Skill skill) {
    switch (slot) {
        case 0:
            skills[slot] = skill;
            break;
        case 1:
            skills[slot] = skill;
            break;
        case 2:
            skills[slot] = skill;
            break;
        default:
            return false;
    }
    
    if (skill.getSpecialty() != specialty) {
        skills[slot] = Skill(); // Remove the learned skill if it doesn't match the Profémon's specialty
        return false;
    }
    
    return true;
}


/*
    @param      :   bool indicating whether or not the Profémon's 
                    skills should be printed
    @post       :   Prints the Profémon's information in a
                    specific format. Additionally, lists
                    the Profémon's skills if the given 
                    'print_skills' parameter is true. Only 
                    print the skills that are not "Undefined"
Format:
(ProfemonName) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
    (SkillNameSlot0) [(Uses)] : (description of skill in slot 0)
    (SkillNameSlot1) [(Uses)] : (description of skill in slot 1)
    (SkillNameSlot2) [(Uses)] : (description of skill in slot 2)

For example:
Maryash [SOFTWARE] | lvl 2 | exp 30/80 | hp 13500
    OOP [30] : a programming paradigm based on the concept of objects
    Vector [30] : a c++ dynamic array library
    Pointer [10] : a pointer stores a memory address

Note: There are four spaces before the each line of skills.
      The last line prints an endline.
*/

void Profemon::printProfemon(bool print_skills) {
    string specialtyStr;
    switch (specialty) {
        case 0:
            specialtyStr = "ML";
            break;
        case 1:
            specialtyStr = "SOFTWARE";
            break;
        case 2:
            specialtyStr = "HARDWARE";
            break;
        default:
            specialtyStr = "Undefined";
    }
    
    cout << name << " [" << specialtyStr << "] | lvl " << level
         << " | exp " << current_exp << "/" << required_exp << " | hp " << max_health << endl;
  
    if (print_skills) {
        for (int i = 0; i < 3; i++) {
            if (skills[i].getName() != "Undefined") {
                cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : " << skills[i].getDescription() << endl;
            }
        }
    }
}


