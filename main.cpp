// Jasleen Kaur Saini
// Homework 1: Priority Queue Project

// Purpose: This program simulates a priority queue for COVID-19 vaccination 
// Takes in patient data from file and vaccine number from command line

#include "COVIDPriorityQueue.h"
#include "Patient.h" 
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

int main() 
{
    // Variable to store the number of available vaccines
    int vaccine_num;

    std::cout << "Enter the Number of Vaccines Available: ";
    // Input for vaccine number parameter 
    std::cin >> vaccine_num;

    if (vaccine_num <= 0) 
    {
        std::cerr << "Error: Invalid Vaccine Input. Please Enter a Positive Integer" << std::endl;
        return 1;
    }

    // creation of priority object 
    COVIDPriorityQueue priority_queue;
    // Reads patient data from the "patients.txt" file and populate the priority queue
    priority_queue.ReadFile("patients.txt");
    // Prints the list of vaccinated patients based on the available number of vaccines
    priority_queue.PrintVaccinatedPatients(vaccine_num);
    return 0;
}
