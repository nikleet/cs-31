/**
 * CS 31, Project 5, PlaneFlight.cpp
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/5/2023
*/

#include "PlaneFlight.h"

using namespace std;

// Constructor
PlaneFlight::PlaneFlight(std::string passengerName, std::string fromCity,
    std::string toCity, double cost, double mileage) {
    PlaneFlight::setName(passengerName);
    PlaneFlight::setFromCity(fromCity);
    PlaneFlight::setToCity(toCity);
    PlaneFlight::setCost(cost);
    PlaneFlight::setMileage(mileage);
}

double PlaneFlight::getCost() {
    return mCost;
}

void PlaneFlight::setCost(double cost) {
    if (cost >= 0)
        mCost = cost;
    else
        mCost = -1;
}

double PlaneFlight::getMileage() {
    return mMileage;
}

void PlaneFlight::setMileage(double mileage) {
    if (mileage > 0)
        mMileage = mileage;
    else
        mMileage = -1;
}

std::string PlaneFlight::getName() {
    return mName;
}

void PlaneFlight::setName(std::string name) {
    if (name != "")
        mName = name;
}

std::string PlaneFlight::getFromCity() {
    return mFromCity;
}

void PlaneFlight::setFromCity(std::string from) {
    if (from != "" && from != mToCity)
        mFromCity = from;
}

std::string PlaneFlight::getToCity() {
    return mToCity;
}

void PlaneFlight::setToCity(std::string to) {
    if (to != "" && to != mFromCity)
        mToCity = to;
}