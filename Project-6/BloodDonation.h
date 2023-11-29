/**
 * CS 31, Project 6, BloodDonation.h
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/15/2023
*/

#ifndef BLOODDONATION_H
#define BLOODDONATION_H

class BloodDonation {
    private:
        int mID;
        int mAge;
        double mWeight;
    public:
        BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight);
        int getID();
        void setID(int id);
        int getAge();
        void setAge(int age);
        double getWeight();
        void setWeight(double weight);
};

#endif