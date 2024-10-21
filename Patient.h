// Jasleen Kaur Saini
// Homework 1: Priority Queue Project

// Purpose: This class represents a patient with a name, age, and illness status, used in the priority queue class

#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient 
{
    public:
        // constructor w/ parameters 
        Patient(const std::string& name, int age, bool hasIllness);

        // getters 
        const std::string& getName() const;
        int getAge() const;
        bool getIllness() const;

    private:
        // private data members 
        std::string name;
        int age;
        bool illness;
};
#endif
