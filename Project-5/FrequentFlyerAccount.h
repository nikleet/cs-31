/**
 * CS 31, Project 5, FrequentFlyerAccount.h
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/5/2023
*/

#ifndef FREQUENTFLYERACCOUNT_H
#define FREQUENTFLYERACCOUNT_H

#include <string>
#include "PlaneFlight.h"

class FrequentFlyerAccount {
private:
    std::string mName;
    double mBalance;

public:
    FrequentFlyerAccount(std::string name);
    double getBalance();
    std::string getName();
    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(std::string from, std::string to, double mileage,
        PlaneFlight& flight);
};

#endif