/**
 * CS 31, Project 6, VacationAccount.h
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/15/2023
*/

#ifndef VACATIONACCOUNT_H
#define VACATIONACCOUNT_H

#include "BloodDonation.h"

class VacationAccount {
    private:
        int mID;
        double mBalance;
    public:
        VacationAccount(int id);
        double getBalance();
        int getID();
        bool addVacationToAccount(BloodDonation donation);
};

#endif
