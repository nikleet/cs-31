// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

/**
 * CS 31, Project 4, array.cpp
 * Name: Niklas Leet
 * UID: 405795083
 * Date: 2/19/2023
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

int locateMaximum(const string array[], int  n);
int countFloatingPointValues(const string array[], int  n);
bool hasNoCapitals(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholder);
void printArray(string array[], int size);


int main() {

    cout << "Testing..." << endl;

    // =========================================================================
    // test locateMaximum 

    string arr1[] = { "a", "d", "c", "b" };
    assert(locateMaximum(arr1, 4) == 1); // test basic functionality

    string arr2[] = { "a", "d", "c", "d" };
    assert(locateMaximum(arr2, 4) == 1); // test duplicate max value

    string arr3[] = { "a", "b", "c", "d" };
    assert(locateMaximum(arr3, 3) == 2); // find max among first 3 values only

    assert(locateMaximum(arr3, -2) == -1);
    assert(locateMaximum(arr3, 0) == -1); // return -1 for invalid n

    string arr4[] = { "a", "b", "c", "d" };
    assert(locateMaximum(arr4, 3) == 2); // find max among first 3 values only

    string arr5[] = { "Z", "Z", "a", "Z" };
    assert(locateMaximum(arr5, 4) == 2); // find max among capitals

    string arr6[] = { "b", "", "", "a" };
    assert(locateMaximum(arr6, 4) == 0); // find max among some empty strings

    string arr7[] = { "", "", "", "" };
    assert(locateMaximum(arr7, 4) == 0); // find max among all empty strings

    // =========================================================================
    // test countFloatingPointValues

    string arr8[] = { "a", "d", "c", "b" };
    assert(countFloatingPointValues(arr8, 4) == 0); // test with no floats

    string arr9[] = { "a", "0.1", "c", "b" };
    assert(countFloatingPointValues(arr9, 4) == 1); // test with one float

    string arr10[] = { "a", "0.1", "00.02", "d" };
    assert(countFloatingPointValues(arr10, 4) == 2); // test multiple float + leading zero

    string arr11[] = { "0.000.1", "12304044.", "0.001", "aasdf", "20.02" };
    assert(countFloatingPointValues(arr11, 5) == 3); // test multiple decimals and no trailing zeroes

    string arr12[] = { "0.000.1", "+12304044.", "0.001", "aasdf", "20.0a2" };
    assert(countFloatingPointValues(arr12, 5) == 1); // test characters in string

    string arr13[] = { "0.000.1", "12304044.", "0.001", "aasdf", ".002" };
    assert(countFloatingPointValues(arr13, 2) == 1); // test first 2 values

    string arr14[] = { "0.000.1", "12304044.", "0.001", "aasdf", ".002" };
    assert(countFloatingPointValues(arr14, 3) == 2); // test first 3 values

    assert(countFloatingPointValues(arr14, -2) == -1);
    assert(countFloatingPointValues(arr14, 0) == -1); // return -1 for invalid n

    // =========================================================================
    // test hasNoCapitals

    string arr15[] = { "a", "d", "c", "b" };
    assert(hasNoCapitals(arr15, 4) == true); // test with no capitals

    string arr16[] = { "2", "0.1", "4", "5" };
    assert(hasNoCapitals(arr16, 4) == true); // test with numbers

    string arr17[] = { "2A901238", "0.afhsd484y1a", "4hliequhfo1y18", "5A&*#^)*#&" };
    assert(hasNoCapitals(arr17, 4) == false); // test with one capital

    string arr18[] = { "", "", "", "" };
    assert(hasNoCapitals(arr18, 4) == true); // empty strings

    string arr19[] = { "2901238", "0.afhsd484y1a", "4hliequhfo1Y18", "5A&*#^)*#&" };
    assert(hasNoCapitals(arr19, 3) == false); // test with one capital, n=3

    string arr20[] = { "2901238", "0.afhsd484y1a", "4hliequhfo1Y18", "5A&*#^)*#&" };
    assert(hasNoCapitals(arr20, 2) == true); // test with one capital, n=2

    // =========================================================================
    // test shiftLeft

    string arr21a[] = { "a", "d", "c", "b" };
    string arr21b[] = { "d", "c", "b", "x" };
    assert(shiftLeft(arr21a, 4, 1, "x") == 1);
    for (int i = 0; i < 4; i++) {
        assert(arr21a[i] == arr21b[i]); // shift left 1
    }

    string arr22a[] = { "a", "d", "c", "b" };
    string arr22b[] = { "b", "x", "x", "x" };
    assert(shiftLeft(arr22a, 4, 3, "x") == 3);
    for (int i = 0; i < 4; i++) {
        assert(arr22a[i] == arr22b[i]); // shift left 3
    }

    string arr23a[] = { "a", "d", "c", "b" };
    string arr23b[] = { "x", "x", "x", "x" };
    assert(shiftLeft(arr23a, 4, 5, "x") == 4);
    for (int i = 0; i < 4; i++) {
        assert(arr23a[i] == arr23b[i]); // shift left 5
    }

    string arr24a[] = { "a", "d", "c", "b" };
    string arr24b[] = { "d", "x", "c", "b" };
    assert(shiftLeft(arr24a, 2, 1, "x") == 1);
    for (int i = 0; i < 4; i++) {
        assert(arr24a[i] == arr24b[i]); // shift left 1, n = 2
    }

    string arr25a[] = { "a", "d", "c", "b" };
    string arr25b[] = { "d", "x", "c", "b" };
    assert(shiftLeft(arr25a, 2, 1, "x") == 1);
    for (int i = 0; i < 4; i++) {
        assert(arr25a[i] == arr25b[i]); // shift left 1, n = 2
    }

    string arr26a[] = { "a", "d", "c", "b" };
    string arr26b[] = { "x", "x", "c", "b" };
    assert(shiftLeft(arr26a, 2, 3, "x") == 2);
    for (int i = 0; i < 4; i++) {
        assert(arr26a[i] == arr26b[i]); // shift left 3, n = 2
    }

    string arr27a[] = { "a", "d", "c", "b" };
    string arr27b[] = { "a", "d", "c", "b" };
    assert(shiftLeft(arr27a, 0, 3, "x") == -1);
    for (int i = 0; i < 4; i++) {
        assert(arr27a[i] == arr27b[i]); // n = 0, return -1
    }

    string arr28a[] = { "a", "d", "c", "b" };
    string arr28b[] = { "a", "d", "c", "b" };
    assert(shiftLeft(arr28a, -1, 3, "x") == -1);
    for (int i = 0; i < 4; i++) {
        assert(arr28a[i] == arr28b[i]); // n <= 0, return -1
    }

    string arr29a[] = { "a", "d", "c", "b" };
    string arr29b[] = { "a", "d", "c", "b" };
    assert(shiftLeft(arr29a, 4, 0, "x") == 0);
    for (int i = 0; i < 4; i++) {
        assert(arr29a[i] == arr29b[i]); // shift 0
    }

    string arr30a[] = { "", "", "", "" };
    string arr30b[] = { "", "", "x", "" };
    assert(shiftLeft(arr30a, 3, 1, "x") == 1);
    for (int i = 0; i < 4; i++) {
        assert(arr30a[i] == arr30b[i]); // n = 3, shift 1, empty string array
    }

    string arr31a[] = { "a", "d", "c", "b" };
    string arr31b[] = { "a", "d", "c", "b" };
    assert(shiftLeft(arr31a, 4, -1, "x") == -1);
    for (int i = 0; i < 4; i++) {
        assert(arr31a[i] == arr31b[i]); // shift < 0, return -1
    }

    string arr32a[] = { "a", "d", "c", "b", "e", "f" };
    string arr32b[] = { "c", "b", "e", "", "", "f" };
    assert(shiftLeft(arr32a, 5, 2, "") == 2);
    for (int i = 0; i < 4; i++) {
        assert(arr31a[i] == arr31b[i]); // n = 5, shift 2, different placeholder
    }

    cout << "All tests completed successfully!" << endl;

    return 0;
}

/**
 * Prints an array.
 *
 * @param array the array to be printed
 * @param num size of the array
*/
void printArray(string array[], int size) {
    static int i;

    if (i == size) {
        i = 0;
        cout << endl;
        return;
    }

    cout << array[i] << " ";
    i++;

    printArray(array, size);

}

/**
 * Returns the index of the largest element of an array of strings.
 *
 * @param array an array of strings
 * @param n the number of elements to be evaluated
 * @returns int index of the largest element or -1 if n <= 0
*/
int locateMaximum(const string array[], int n) {
    if (n <= 0)
        return -1;

    int maxIndex = n - 1;

    for (int i = n - 1; i >= 0; i--)
        if (array[i] >= array[maxIndex])
            maxIndex = i;

    return maxIndex;
}

/**
 * Returns the number of elements in a string array that contain valid
 * representations of floating point numbers.
 *
 * @param array an array of strings
 * @param n the number of elements to be evaluated
 * @returns int number of valid floating point strings or -1 if n <= 0
*/
int countFloatingPointValues(const string array[], int  n) {
    if (n <= 0)
        return -1;

    int floatCount = 0;

    for (int i = 0; i < n; i++) {
        int decimalCount = 0;
        bool isValid = true;

        for (int j = 0; j < array[i].size(); j++) {
            if (array[i].at(j) == '.')
                decimalCount++;
            else if (!isdigit(array[i].at(j)))
                isValid = false;
        }

        if (isValid && decimalCount <= 1)
            floatCount++;
    }

    return floatCount;
}

/**
 * Returns true if all elements of a string array contain no capital letters.
 *
 * @param array an array of strings
 * @param n the number of elements to be evaluated
 * @returns boolean true if there are no capitals, false otherwise
*/
bool hasNoCapitals(const string array[], int n) {
    for (int i = 0; i < n; i++)
        for (char c : array[i])
            if (c != tolower(c))
                return false;

    return true;
}

/**
 * Shifts the first n elements of a string array left by a specified amount.
 *
 * @param array an array of strings
 * @param n the first elements to be shifted
 * @param amount the amount of places the elements will be shifted to the left
 * @returns int number of times the placeholder value was used
*/
int shiftLeft(string array[], int n, int amount, string placeholder) {
    if (n <= 0 || amount < 0)
        return -1;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i - amount >= 0)
            array[i - amount] = array[i];

        if (i >= n - amount) {
            array[i] = placeholder;
            count++;
        }
    }

    return count;
}
