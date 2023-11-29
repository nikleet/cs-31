/*
    CS 31 Project 3, qctest.cpp
    Name: Niklas Leet
    Date: 2/5/2023
    UID: 405795083
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

bool isValidQC(string results);
int stringToNum(string str);
int passQC(string results);
int defect(string results);
int totalQC(string results);
int batches(string results);

int main() {
    string input;

    while (true) {   
        cout << "Enter a QC string: ";
        getline(cin, input);
        cout << "Valid:\t\t" << (isValidQC(input) ? "Yes" : "No") << endl; 
        cout << "Passes:\t\t" << passQC(input) << endl;
        cout << "Defects:\t" << defect(input) << endl;
        cout << "Total tests:\t" << totalQC(input) << endl;
        cout << "Batches:\t" << batches(input) << endl << endl;
    }

    return 0;
}

/*
    Checks if a QC string is valid. For each batch to be valid,
    1.  'Q', 'p', 'd', and digits are the only characters in the string.
    2.  Every Q must be followed by a 'p' and 'd'.
    3.  Numbers following 'Q', 'p', and 'd' must not have a leading zero.
    4.  'Q' must not be followed by 0. 
    5.  The number of tests must equal the number of passes + defects.
*/
bool isValidQC(string results) {
    int next_p;
    int next_d;
    int batch_end = results.find('Q', 1) < 0
                    ? results.find('Q', 1)
                    : results.length() - 1;
    int tests = 0;
    int passes = 0;
    int defects = 0;

    if(results == "") {
        return false;
    }

    for (int i = 0; i < results.length(); i++) {
        
        if(i == batch_end && (tests <= 0 || tests != passes + defects)) {
            return false;
        }
        
        if (results[i] == 'Q') {
            batch_end = results.find('Q', i + 1) < 0
                        ? results.find('Q', i + 1)
                        : results.length() - 1;
            next_d = results.find('d', i + 1);
            next_p = results.find('p', i + 1);
            
            // returns false if Q is not followed by 'p','d', and a nonzero num
            if (next_p > i 
                && next_d > i 
                && next_p < batch_end 
                && next_d < batch_end 
                && stringToNum(results.substr(i + 1)) > 0) { 
                tests += stringToNum(results.substr(i + 1));
            } else {
                return false;
            }
        }
        else if (results[i] == 'p') {
            if (stringToNum(results.substr(i + 1)) >= 0) {
                passes += stringToNum(results.substr(i + 1));
            } else {
                return false;
            }
        }
        else if (results[i] == 'd') {
            if(stringToNum(results.substr(i + 1)) >= 0) {
                defects += stringToNum(results.substr(i + 1));
            } else {
                return false;
            }
        }
        else if (!isdigit(results[i])) {
            return false;
        }
    }

    return true;
}

/*
    Uses stoi to convert characters representing a number at the start of a 
    string into an int if that number meets the criteria for validity. 
    Otherwise, returns -1. For a an inputted string to be valid, it must have no
    leading zeroes, nonzero length, and it must start with a digit.  
*/
int stringToNum(string str) {
    if ((str.length() > 1 && str[0] == '0' && isdigit(str[1]))
        || str.length() == 0
        || !isdigit(str[0])) {
        return -1;
    }
    
    return stoi(str);
}

/*
    Returns the number of passed tests in all batches if a QC string is valid.
    Otherwise, returns -1. 
*/
int passQC(string results) {
    int passes = 0;

    if (!isValidQC(results)) {
        return -1;
    }

    for (int i = 0; i < results.length(); i++) {
        if(results[i] == 'p') {
            passes += stringToNum(results.substr(i + 1));
        }
    }
    
    return passes;
}

/*
    Returns the number of passed tests in all batches if a QC string is valid.
    Otherwise, returns -1. 
*/
int defect(string results) {
    int defects = 0;
    
    if (!isValidQC(results)) {
        return -1;
    }

    for (int i = 0; i < results.length(); i++) {
        if (results[i] == 'd') {
            defects += stringToNum(results.substr(i + 1));
        }
    }

    return defects;
}

/*
    Returns the total number of tests in all batches if a QC string is valid.
    Otherwise, returns -1. 
*/
int totalQC(string results) {
    int tests = 0;
    
    if (!isValidQC(results)) {
        return -1;
    }

    for (int i = 0; i < results.length(); i++) {
        if (results[i] == 'Q') {
            tests += stringToNum(results.substr(i + 1));
        }
    }

    return tests;
}

// Returns the number of batches if a QC string is valid. Otherwise, returns -1.
int batches(string results) {
    int batches = 0;
    
    if (!isValidQC(results)) {
        return -1;
    }
    
    for (int i = 0; i < results.length(); i++) {
        if (results[i] == 'Q') {
            batches++;
        }
    }

    return batches;
}