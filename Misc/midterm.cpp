#include <iostream>
#include <cassert>

using namespace std;


int func(int n, double d);

int main() {
    int n = 7;
    double d = 2.0;
    func(n, d);
    return 0;
}


int func(int n, double d)
{
    int j = n;
    double sum = 0;
    while( j >= 0)
    {
        sum += d;
        -j;
    }
    return sum;
}