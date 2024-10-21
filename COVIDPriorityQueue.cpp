// Jasleen Kaur Saini
// Homework 1: Priority Queue Project

// Purpose: This class represents a priority queue for managing COVID vaccinations

#include "COVIDPriorityQueue.h"

// function purpose/conditions: Checks if the priority queue is empty
bool COVIDPriorityQueue::Empty() const 
{
    return priority_queue.empty();
}

// function purpose/conditions: Adds a patient to the priority queue.
void COVIDPriorityQueue::Push(const Patient& patient) 
{
    priority_queue.push(patient);
}

// function purpose/conditions: Removes the highest-priority patient from the queue
void COVIDPriorityQueue::Pop() 
{
    priority_queue.pop();
}

// function purpose/conditions: Retrieves the highest-priority patient from queue
const Patient& COVIDPriorityQueue::Top() const 
{
    return priority_queue.top();
}

// function purpose/conditions: Reads patient data from a file and adds to priority queue
void COVIDPriorityQueue::ReadFile(const std::string& file_name) 
{
    // open file 
    std::ifstream input_file(file_name);
    if (!input_file.is_open()) {
        std::cerr << "Error: Failed to Open " << file_name << std::endl;
        return;
    }

    std::string command;
    while (getline(input_file, command)) 
    {
        // patient data variables 
        std::string name;
        std::string age_input;
        std::string illnesses_input;
        std::stringstream ss(command);

        // seperates patient data lines from file 
        getline(ss, name, ',');  
        getline(ss, age_input, ','); 
        getline(ss, illnesses_input);  

        // format age 
        age_input.erase(0, age_input.find_first_not_of(' '));
        age_input.erase(age_input.find_last_not_of(' ') + 1);
        // format illness
        illnesses_input.erase(0, illnesses_input.find_first_not_of(' '));
        illnesses_input.erase(illnesses_input.find_last_not_of(' ') + 1);

        // Convert age conversion 
        int age = 0;
        try 
        {
            age = std::stoi(age_input);
        } 
        catch (const std::invalid_argument& a) 
        {
            continue;
        }

        // illness conversion  
        for (char& c : illnesses_input) 
        {
            c = std::toupper(c);
        } 
        bool illness = (illnesses_input == "YES");

        // create patient object and push onto priority queue (age constraint)
        if (age >= 5) {
            Patient patient(name, age, illness);
            Push(patient);
        }
    }
    // close file 
    input_file.close();
}

// function purpose/conditions: Prints the list of vaccinated patients based on the available number of vaccines
void COVIDPriorityQueue::PrintVaccinatedPatients(int vaccine_num) 
{
    std::cout << "Patient Vaccination Output:" << std::endl;
    int queue_count = 0;
    // output: patient name from queue 
    while (!Empty() && queue_count < vaccine_num) 
    {
        std::cout << Top().getName() << std::endl;
        // remove and increment patient 
        Pop();
        queue_count++;
    }
    std::cout << " " << std::endl; 
    // output: vaccines given statistic 
    std::cout << "Used " << queue_count << " out of " << vaccine_num << " available vaccines." << std::endl;
}
