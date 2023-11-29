/**
 * CS 31, Project 5, FrequentFlyerAccount.cpp
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/5/2023
*/

#include "FrequentFlyerAccount.h"
#include <string>


// Constructor
FrequentFlyerAccount::FrequentFlyerAccount(std::string name) {
    mName = name;
    mBalance = 0;
}

double FrequentFlyerAccount::getBalance() {
    return mBalance;
}

std::string FrequentFlyerAccount::getName() {
    return mName;
}

// Returns true if flight name matches account name and the flight is not free;
// false otherwise.
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    if (flight.getName() == mName && flight.getCost() > 0) {
        mBalance += flight.getMileage();
        return true;
    }

    return false;
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    if (mBalance >= mileage)
        return true;

    return false;
}

// If the account has sufficient balance for a flight of double mileage and
// the from and to strins are valid, creates a free flight at &flight with the
// provided details, the account name, and zero cost.  
bool FrequentFlyerAccount::freeFlight(std::string from, std::string to, double mileage,
    PlaneFlight& flight) {
    if (canEarnFreeFlight(mileage) && from != to && from != "" && to != "" 
        && mileage > 0) {
        flight = PlaneFlight(mName, from, to, 0, mileage);
        mBalance -= mileage;
        return true;
    }

    return false;
}