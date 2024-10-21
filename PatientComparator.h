// Jasleen Kaur Saini
// Homework 1: Priority Queue Project

// Purpose: This class defines a comparator for comparing Patient objects in the priority queue

#ifndef PATIENT_COMPARATOR_H
#define PATIENT_COMPARATOR_H

#include "Patient.h"

class PatientComparator 
{
    public:
        // comparator function 
        // function purpose/conditions: overloaded operator() function that compares two Patient objects to determine higher priority 
        bool operator()(const Patient& patient, const Patient& next) const;
};
#endif
