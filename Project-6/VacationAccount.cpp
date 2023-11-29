/**
 * CS 31, Project 6, VacationAccount.cpp
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/15/2023
*/

#include "VacationAccount.h"
#include "BloodDonation.h"

using namespace std;

VacationAccount::VacationAccount(int id) {
    mBalance = 0;
    if(99999 < id && id < 1000000)
        mID = id;
    else 
        mID = -1; 
}

double VacationAccount::getBalance() {
    return mBalance;
}

int VacationAccount::getID() {
    return mID;
}

// adds four hours to vacation account balance and returns true if donation id 
// matches account id and both are valid, returns false otherwise. 
bool VacationAccount::addVacationToAccount(BloodDonation donation) {
    if(mID == donation.getID() && mID != -1 && donation.getID() != -1
        && donation.getAge() != -1
        && donation.getWeight() != -1) {
            mBalance += 4;
            return true;
        }
    return false;
}