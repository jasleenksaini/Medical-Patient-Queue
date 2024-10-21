// Jasleen Kaur Saini
// Homework 1: Priority Queue Project

// Purpose: This class represents a priority queue for managing COVID vaccinations

#ifndef COVIDPRIORITYQUEUE_H
#define COVIDPRIORITYQUEUE_H    

#include "Patient.h"
#include "PatientComparator.h"
#include <queue>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

class COVIDPriorityQueue 
{
    public:
        // default constructor 
        COVIDPriorityQueue() = default;

        // functions/actions 
        // function purpose/conditions: Checks if the priority queue is empty
        bool Empty() const;
        // function purpose/conditions: Adds a patient to the priority queue.
        void Push(const Patient& patient);
        // function purpose/conditions: Removes the highest-priority patient from the queue
        void Pop();
        // function purpose/conditions: Retrieves the highest-priority patient from queue
        const Patient& Top() const;
        
        // input/output file functions 
        // function purpose/conditions: Reads patient data from a file and adds to priority queue
        void ReadFile(const std::string& file_name);
        // function purpose/conditions: Prints the list of vaccinated patients based on the available number of vaccines
        void PrintVaccinatedPatients(int vaccine_num);

    private:
        // private data member: priority queue 
        std::priority_queue<Patient, std::vector<Patient>, PatientComparator> priority_queue;
};
#endif
