/**
 * CS 31, Project 7, main.cpp
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 3/15/2023
*/

#include <iostream>
#include <string>
#include <cassert>
#include "BloodDonation.h"
#include "VacationAccount.h"
using namespace std;
int main()
{
    // sample test code
    BloodDonation doner1( 752401, 45, 99.56);
    BloodDonation doner2( 889543, 55, 109.50);
    BloodDonation doner3( 89643244, 65, 187.55);
    BloodDonation doner4( 855565, 17, 127.00);
    VacationAccount account(889543);
    assert( std::to_string(doner1.getID( )) == "752401");
    assert(std::to_string(doner2.getAge( )) == "55" );
    assert(doner3.getWeight( ) == 187.55 );
    // account balance starts at zero...
    assert( std::to_string(account.getBalance( ) ) == "0.000000" );
    assert( std::to_string(account.getID( )) == "889543");
    // Vacation adds to vacation balance
    assert( account.addVacationToAccount( doner2 ) == true );
    assert( account.addVacationToAccount( doner1 ) == false );
    assert( std::to_string( account.getBalance( ) ) == "4.000000" );

    BloodDonation donor5(99999, 22, 140);
    BloodDonation donor6(1000000, 22, 140);
    BloodDonation donor7(999999, 22, 140);
    BloodDonation donor8(100000, 22, 140);

    assert(donor5.getID() == -1);
    assert(donor6.getID() == -1);
    assert(donor7.getID() == 999999);
    assert(donor8.getID() == 100000);

    cout << "All tests passed." << endl;
    return 0;
}