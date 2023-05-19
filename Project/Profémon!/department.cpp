#include <iostream>
#include <vector>
#include "department.hpp"
#include "skill.hpp"
#include "profemon.hpp"
#include "trainer.hpp"

MLDepartment::MLDepartment(std::vector<Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++)
    {
        if (profemons[i].getSpecialty() == Specialty::ML)
        {
            addProfemon(profemons[i]);
        }
    }
}

bool MLDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() == Specialty::ML)
    {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons)
{
    for (int i = 0; i < profemons.size(); i++)
    {
        if (profemons[i].getSpecialty() == Specialty::SOFTWARE)
        {
            addProfemon(profemons[i]);
        }
    }
}

bool SoftwareDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() == Specialty::SOFTWARE)
    {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons) 
{
    for (int i = 0; i < profemons.size(); i++)
    {
        if (profemons[i].getSpecialty() == Specialty::HARDWARE)
        {
            addProfemon(profemons[i]);
        }
    }
}

bool HardwareDepartment::addProfemon(Profemon profemon)
{
    if (profemon.getSpecialty() == Specialty::HARDWARE)
    {
        return Trainer::addProfemon(profemon);
    }
    return false;
}

