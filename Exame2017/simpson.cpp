#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double f(double x) { return sqrt(1 + pow(2.5 * exp(2.5 * x), 2)); }

int main()
{
    double h = 0.25, a = 1, b = 2, integral = 0;

    for (double i = a + h; i < b; i = i + h + h)
    {
        integral += (f(i) * 4);
    }

    for (double i = a + h * 2; i < b; i = i + h + h)
    {
        integral += (f(i) * 2);
    }

    integral += f(a);
    integral += f(b);

    integral *= (h / 3);

    cout << "Integral value: " << integral;
}
