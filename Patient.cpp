// Jasleen Kaur Saini
// Homework 1: Priority Queue Project

// Purpose: This class represents a patient with a name, age, and illness status, used in the priority queue class

#include "Patient.h"

// constructors with parameters 
Patient::Patient(const std::string& name, int age, bool illness)
{
    this->name = name;
    this->age = age;
    this->illness = illness;
}

// getters 
const std::string& Patient::getName() const 
{
    return name;
}

int Patient::getAge() const 
{
    return age;
}

bool Patient::getIllness() const 
{
    return illness;
}
