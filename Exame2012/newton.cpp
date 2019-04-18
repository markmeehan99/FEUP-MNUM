#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {return (x-3.7) + pow(cos(x + 1.2), 3);}

double fx(double x) {return 1 - 3 * pow(cos(x+1.2), 2) * sin(x+1.2);}

int main()
{
    double x = 3.8;

    x = x - f(x) / fx(x);

    cout << x << endl;
}