#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double f(double x) { return sqrt(1 + pow(2.5 * exp(2.5 * x), 2)); }

int main()
{
    double h = 0.125, a = 0, b = 1, integral = 0;

    for (double i = a + h; i < b; i += h)
        integral += (2 * f(i));

    integral += f(a);

    integral += f(b);

    integral *= (h / 2);

    cout << "Integral value: " << integral;
}