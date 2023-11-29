/**
 * CS 31, Project 5, main.cpp
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/5/2023
*/

#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cassert>

using namespace std;

int main() {
    FrequentFlyerAccount account1("Jim");
    // Invalid values for constructor
    PlaneFlight account1Flight("Elle", "OAK", "AZP", 69., 420.);
    
    
    string name;
    double balance;

    // Test FrequentFlyerAccount accessors
    name = account1.FrequentFlyerAccount::getName();
    balance = account1.FrequentFlyerAccount::getBalance();

    cout << "Account details:\nName:\t\t" << name << "\nBalance:\t" << balance
        << endl;

    // Test PlaneFlight accessors

    string fName, from, to;
    double cost, mileage;
    fName = account1Flight.PlaneFlight::getName();
    from = account1Flight.PlaneFlight::getFromCity();
    to = account1Flight.PlaneFlight::getToCity();
    cost = account1Flight.PlaneFlight::getCost();
    mileage = account1Flight.PlaneFlight::getMileage();

    cout << "\nFlight Details:\nName:\t\t" << fName << "\nFrom:\t\t" << from
        << "\nTo:\t\t" << to << "\nCost:\t\t" << cost << "\nMileage:\t"
        << mileage << "\n\nChanging flight details..." << endl;

    // Test PlaneFlight mutators
    account1Flight.PlaneFlight::setName("Bob");
    account1Flight.PlaneFlight::setFromCity("SFO");
    account1Flight.PlaneFlight::setToCity("LAX"); // check names can't match!
    account1Flight.PlaneFlight::setCost(150.);
    account1Flight.PlaneFlight::setMileage(210.4);

    fName = account1Flight.PlaneFlight::getName();
    from = account1Flight.PlaneFlight::getFromCity();
    to = account1Flight.PlaneFlight::getToCity();
    cost = account1Flight.PlaneFlight::getCost();
    mileage = account1Flight.PlaneFlight::getMileage();

    cout << "\nUpdated Flight Details:\nName:\t\t" << fName << "\nFrom:\t\t" << from
        << "\nTo:\t\t" << to << "\nCost:\t\t" << cost << "\nMileage:\t"
        << mileage << endl;

    if (account1.FrequentFlyerAccount::addFlightToAccount(account1Flight))
        cout << "\nAdded ";
    else
        cout << "\nCould not add ";
    cout << fName << "'s flight  to " << name << "'s account." << endl;

    account1Flight.PlaneFlight::setName("Jim");
    cout << "\nFlightholder's name changed to " << account1Flight.getName() << "." << endl;

    // Test PlaneFlight mutators do not store same origin and destination

    string newDest = "SFO";
    cout << "\nAttempting to change destination to " << newDest << ", which matches the origin, " 
        << account1Flight.getFromCity() << ".\nCurrent destination : \t\t\t" << account1Flight.getToCity() 
        << endl;
    
    account1Flight.PlaneFlight::setToCity(newDest);
    cout << "New destination (should be unchanged):\t" << account1Flight.getToCity() << endl;

    string newOri = "LAX";
    cout << "\nAttempting to change origin to " << newOri << ", which matches the destination, "
        << account1Flight.getToCity() << ".\nCurrent origin : \t\t\t" << account1Flight.getFromCity()
        << endl;
    
    account1Flight.PlaneFlight::setFromCity(newOri);
    cout << "New origin (should be unchanged):\t" << account1Flight.getFromCity() << endl;

    if (account1.FrequentFlyerAccount::addFlightToAccount(account1Flight))
        cout << "\nAdded ";
    else
        cout << "\nCould not add ";
    cout << account1Flight.getName()  << "'s flight to " << account1Flight.getToCity() << " to "
        << account1.getName() << "'s account." << endl;
    // Check updated balance
    cout << account1.getName() << "'s new mileage balance:\t\t\t" << account1.getBalance() 
        << endl << endl;

    // Test canEarnFreeFlight
    double freeFlightMileage;
    string canEarnFreeFlight;
    freeFlightMileage = 2600;
    canEarnFreeFlight = (account1.canEarnFreeFlight(freeFlightMileage) ? "Yes" : "No");
    PlaneFlight freeFlight1("", "", "", -1, -1);
    from = "NYC";
    to = "ABC";
    cout << "Can he earn a free flight of " << freeFlightMileage << " miles?\t" << canEarnFreeFlight << endl;
    if(account1.freeFlight(from, to, freeFlightMileage, freeFlight1))
        cout << "Free flight of " << freeFlightMileage << " added.\n" << account1.getName()
        << "'s new mileage balance:\t\t\t" << account1.getBalance() << endl << endl;

    // Test canEarnFreeFlight
    freeFlightMileage = 160;
    canEarnFreeFlight = (account1.canEarnFreeFlight(freeFlightMileage) ? "Yes" : "No");
    PlaneFlight freeFlight2("", "", "", -1, -1);
    from = "NYC";
    to = "COH";
    cout << "Can he earn a free flight of " << freeFlightMileage << " miles?\t\t" << canEarnFreeFlight << endl;
    
    if (account1.freeFlight(from, to, freeFlightMileage, freeFlight2))
        cout << "Free flight of " << freeFlightMileage << " added.\n" << account1.getName() 
            << "'s new mileage balance:\t\t\t" << account1.getBalance() << endl << endl;
           
    // sample test code  
    PlaneFlight shortleg( "Howard", "LAX", "LAS", 49.00, 285 ); 
    PlaneFlight longleg( "Howard", "LAS", "NYC", 399.00, 2800 ); 
    PlaneFlight sample( "Sample", "Sample", "Sample", 0, 1 ); 
    FrequentFlyerAccount account( "Howard" ); 
    assert( shortleg.getFromCity( ) == "LAX" ); 
    assert( shortleg.getToCity( ) == "LAS" ); 
    assert( shortleg.getName( ) == "Howard" ); 
    assert( std::to_string( shortleg.getCost( ) ) == "49.000000" ); 
    assert( std::to_string( shortleg.getMileage( ) ) == "285.000000" ); 

    // account balance starts at zero... 
    assert( std::to_string( account.getBalance( ) ) == "0.000000" ); 
    assert( account.getName( ) == "Howard" ); 
    assert( account.canEarnFreeFlight( 3300.00 ) == false ); 

    // flights add to an account balance 
    assert( account.addFlightToAccount( shortleg ) == true );  // returns true because the names match  
    assert( account.addFlightToAccount( longleg ) == true );   // returns true because the names match 
    assert( std::to_string( account.getBalance( ) ) == "3085.000000" );  
    // free flights reduce an account balance 
    if (account.canEarnFreeFlight( 285 )) 
    { 
        assert( account.freeFlight( "LAS", "LAX", 285, sample ) == true ); 
        // Howard earned a free flight... 
        assert( sample.getName( ) == "Howard" ); 
        assert( std::to_string( sample.getCost( ) ) == "0.000000" ); 
        assert( sample.getFromCity( ) == "LAS" ); 
        assert( sample.getToCity( ) == "LAX" ); 
        assert( std::to_string( sample.getMileage( ) ) == "285.000000" ); 
        // account has been reduced for this free flight... 
        assert( std::to_string( account.getBalance( ) ) == "2800.000000" ); 
    } 
    else  
    { 
        assert( false );  // there are enough miles in the account... 
    } 
    // non-matching names are ignored 
    PlaneFlight muffin( "Muffin", "LAX", "Doggie Heaven", 500, 500 ); 
    assert( account.addFlightToAccount( muffin ) == false ); 
    assert( std::to_string( account.getBalance( ) ) == "2800.000000" ); 
    cout << "all tests passed!" << endl; 
        

    return 0;
}