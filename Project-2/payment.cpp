/*
    Name: Niklas Leet
    Project 2
    UID: 405795083
*/

#include <iostream>
#include <string>

using namespace std;

// variables
string state;
string month;
short day;
short year;
bool tax_free = false;
float purchase_amount;
float state_tax;
float local_tax;
float levy;
float payment_amount;


int main() {

    // gather user input for state, amount, month, day, and year
    cout << "State Name: ";
    getline(cin, state);
    cout << "Purchase amount: ";
    cin >> purchase_amount;
    cout << "Provide the month: ";
    cin.ignore();
    getline(cin, month);
    cout << "Provide the day: ";
    cin >> day;
    cout << "Provide the year: ";
    cin >> year;

// set state tax, local tax, and levy as well as tax free status depending on state
    if(state == "Alabama") {
        state_tax = 4;
        local_tax = 5.14;
        levy = 0;
        if(month == "July" && 15 <= day && day <= 17)
            tax_free = true;
    }
    else if(state == "Alaska") {
        state_tax = 0;
        local_tax = 1.43;
        levy = 0;
    }
    else if(state == "Arizona") {
        state_tax = 5.6;
        local_tax = 2.77;
        levy = 0;
    }
    else if(state == "Arkansas") {
        state_tax = 6.5;
        local_tax = 2.93;
        levy = 0;
        if(month == "August" && 6 <= day && day <= 7)
            tax_free = true;
    }
    else if(state == "California") {
        state_tax = 7.25;
        local_tax = 1.31;
        levy = 1;
    }
    else if(state == "Colorado") {
        state_tax = 2.9;
        local_tax = 4.73;
        levy = 0;
    }
    else if(state == "Connecticut") {
        state_tax = 6.35;
        local_tax = 0;
        levy = 0;
        if(month == "August" && 21 <= day && day <= 27)
            tax_free = true;
    }
    else if(state == "Delaware") {
        state_tax = 0;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "Florida") {
        state_tax = 6;
        local_tax = 1.05;
        levy = 0;
    }
    else if(state == "Georgia") {
        state_tax = 4;
        local_tax = 3.29;
        levy = 0;
    }
    else if(state == "Hawaii") {
        state_tax = 4;
        local_tax = .41;
        levy = 0;
    }
    else if(state == "Idaho") {
        state_tax = 6;
        local_tax = .03;
        levy = 0;
    }
    else if(state == "Illinois") {
        state_tax = 6.25;
        local_tax = 2.49;
        levy = 0;
    }
    else if(state == "Indiana") {
        state_tax = 7;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "Iowa") {
        state_tax = 6;
        local_tax = .82;
        levy = 0;
        if(month == "August" && 5 <= day && day <= 6)
            tax_free = true;
    }
    else if(state == "Kansas") {
        state_tax = 6.5;
        local_tax = 2.17;
        levy = 0;
    }
    else if(state == "Kentucky") {
        state_tax = 6;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "Louisiana") {
        state_tax = 4.45;
        local_tax = 5;
        levy = 0;
    }
    else if(state == "Maine") {
        state_tax = 5.5;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "Maryland") {
        state_tax = 6;
        local_tax = 0;
        levy = 0;
        if(month == "August" && 14 <= day && day <= 20)
            tax_free = true;
    }
    else if(state == "Massachusetts") {
        state_tax = 6.25;
        local_tax = 0;
        levy = 0;
        if(month == "August" && 14 <= day && day <= 15)
            tax_free = true;
    }
    else if(state == "Michigan") {
        state_tax = 6;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "Minnesota") {
        state_tax = 6.88;
        local_tax = .55;
        levy = 0;
    }
    else if(state == "Mississippi") {
        state_tax = 7;
        local_tax = .07;
        levy = 0;
        if(month == "July" && 29 <= day && day <= 30)
            tax_free = true;
    }
    else if(state == "Missouri") {
        state_tax = 4.23;
        local_tax = 3.9;
        levy = 0;
        if(month == "April" && 19 <= day && day <= 25)
            tax_free = true;
    }
    else if(state == "Montana") {
        state_tax = 0;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "Nebraska") {
        state_tax = 5.5;
        local_tax = 1.35;
        levy = 0;
    }
    else if(state == "Nevada") {
        state_tax = 6.85;
        local_tax = 1.29;
        levy = 0;
        if(month == "August" && 5 <= day && day <= 7)
            tax_free = true;
    }
    else if(state == "New Hampshire") {
        state_tax = 0;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "New Jersey") {
        state_tax = 6.63;
        local_tax = -.03;
        levy = 0;
    }
    else if(state == "New Mexico") {
        state_tax = 5.13;
        local_tax = 2.69;
        levy = 0;
    }
    else if(state == "New York") {
        state_tax = 4;
        local_tax = 4.49;
        levy = 0;
    }
    else if(state == "North Carolina") {
        state_tax = 4.75;
        local_tax = 2.22;
        levy = 0;
    }
    else if(state == "North Dakota") {
        state_tax = 5;
        local_tax = 1.85;
        levy = 0;
    }
    else if(state == "Ohio") {
        state_tax = 5.75;
        local_tax = 1.42;
        levy = 0;
        if(month == "August" && 5 <= day && day <= 7)
            tax_free = true;
    }
    else if(state == "Oklahoma") {
        state_tax = 4.5;
        local_tax = 4.42;
        levy = 0;
        if(month == "August" && 6 <= day && day <= 8)
            tax_free = true;
    }
    else if(state == "Oregon") {
        state_tax = 0;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "Pennsylvania") {
        state_tax = 6;
        local_tax = .34;
        levy = 0;
    }
    else if(state == "Rhode Island") {
        state_tax = 7;
        local_tax = 0;
        levy = 0;
    }
    else if(state == "South Carolina") {
        state_tax = 6;
        local_tax = 1.43;
        levy = 0;
        if(month == "August" && 5 <= day && day <= 7)
            tax_free = true;
    }
    else if(state == "South Dakota") {
        state_tax = 4.5;
        local_tax = 1.9;
        levy = 0;
    }
    else if(state == "Tennessee") {
        state_tax = 7;
        local_tax = 2.47;
        levy = 0;
        if(month == "July" && 29 <= day && day <= 31)
            tax_free = true;
    }
    else if(state == "Texas") {
        state_tax = 6.25;
        local_tax = 1.94;
        levy = 0;
        if(month == "August" && 5 <= day && day <= 7)
            tax_free = true;
    }
    else if(state == "Utah") {
        state_tax = 5.95;
        local_tax = .99;
        levy = 1.25;
    }
    else if(state == "Vermont") {
        state_tax = 6;
        local_tax = .18;
        levy = 0;
    }
    else if(state == "Virginia") {
        state_tax = 5.3;
        local_tax = .35;
        levy = 1;
    }
    else if(state == "Washington") {
        state_tax = 6.5;
        local_tax = 2.67;
        levy = 0;
    }
    else if(state == "West Virginia") {
        state_tax = 6;
        local_tax = .39;
        levy = 0;
        if(month == "August" && 5 <= day && day <= 7)
            tax_free = true;
    }
    else if(state == "Winsconsin") {
        state_tax = 5;
        local_tax = .44;
        levy = 0;
    }
    else if(state == "Wyoming") {
        state_tax = 4;
        local_tax = 1.36;
        levy = 0;
    }
    else {
        // error if input does not match states
        cout << "Invalid state!";
        return -1;
    }
    
    // check for erroneous input of purchase amount, month, day, and year
    if(purchase_amount <= 0) {
        cout << "Invalid amount!";
        return -1;
    } 

    if(month != "January" && month != "February" && month != "March" 
            && month != "April" && month != "May" && month != "June" 
            && month != "July" && month != "August" && month != "September"
            && month != "October" && month != "November" && month != "December") {
            
            cout << "Invalid month!";
            return -1;
        }
    
    if(day < 1 || day > 31) {
        cout << "Invalid day!";
        return -1;
    }
    
    if(year < 1 || year > 2025) {
        cout << "Invalid year!";
        return -1;
    }

    // calculate and print final payment amount
    if(tax_free)
        payment_amount = purchase_amount;
    else
        payment_amount = purchase_amount * (1 + (state_tax + local_tax + levy) / 100);
    cout << "Please pay a total of $";
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << payment_amount;

    return 0;
}