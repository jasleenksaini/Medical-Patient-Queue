// Jasleen Kaur Saini
// Homework 1: Priority Queue Project

// Purpose: This class defines a comparator for comparing Patient objects in the priority queue

#include "PatientComparator.h"

// function purpose/conditions: overloaded operator() function that compares two Patient objects to determine higher priority
bool PatientComparator::operator()(const Patient& patient, const Patient& next) const 
{
    // illness comparison 
    if (!patient.getIllness() && next.getIllness()) 
    {
        return true; 
    } 
    if (patient.getIllness() && !next.getIllness()) 
    {
        return false;  
    } 
    // age comparison 
    if (patient.getAge() < next.getAge()) 
    {
        return true;  
    } 
    // else case: no illness + youngest 
    return false;  
}


