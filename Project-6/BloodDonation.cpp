/**
 * CS 31, Project 6, BloodDonation.cpp
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/15/2023
*/

#include "BloodDonation.h"

using namespace std;

BloodDonation::BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight) {
    setID(EmployeeID);
    setAge(EmployeeAge);
    setWeight(EmployeeWeight);
}

int BloodDonation::getID() {
    return mID;
}

void BloodDonation::setID(int id) {
    if(99999 < id && id < 1000000)
        mID = id;
    else 
        mID = -1; 
}

int BloodDonation::getAge() {
    return mAge;
}

void BloodDonation::setAge(int age) {
    if(21 <= age && age <= 65)
        mAge = age;
    else
        mAge = -1;
}

double BloodDonation::getWeight() {
    return mWeight;
}

void BloodDonation::setWeight(double weight) {
    if(101. <= weight && weight <= 280.)
        mWeight = weight;
    else
        mWeight = -1;
}