/**
 * CS 31, Project 5, PlaneFlight.h
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/5/2023
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <string>

class PlaneFlight {
private:
    double mCost;
    std::string mFromCity;
    std::string mToCity;
    std::string mName;
    double mMileage;

public:
    PlaneFlight(std::string passengerName, std::string fromCity,
        std::string toCity, double cost, double mileage);
    double getCost();
    void setCost(double cost);
    double getMileage();
    void setMileage(double mileage);
    std::string getName();
    void setName(std::string name);
    std::string getFromCity();
    void setFromCity(std::string from);
    std::string getToCity();
    void setToCity(std::string to);
};

#endif