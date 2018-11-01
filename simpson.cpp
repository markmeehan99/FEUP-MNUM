#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

double f(double x) { return (x*x - 4*x + 3.5); }	// f(x) = x^2 - 4*x + 3.5

void simpson(double a, double b, double h);

int main()
{
    double a = 2;
    double b = 6;
    double h = 0.1;

    simpson(a,b,h);
}

void simpson(double a, double b, double h)
{
    vector<double>values;
    double n = abs(b-a)/h;
    double integral_even = 0;
    double integral_odd = 0;
    double integral = 0;

    for(int i = 0; i <= n; i++)
    {
        values.push_back(f(a + i*h));
    }

    for (int i = 1; i < n; i+=2)
        integral_odd += values.at(i);

    for (int i = 2; i < n; i+=2)
        integral_even += values.at(i);

    integral_odd *= 4;
    integral_even *= 2;

    integral += integral_even;
    integral += integral_odd;

    integral += values.at(0);
    integral += values.at(n);

    integral *= h/3;

    cout << integral;
}