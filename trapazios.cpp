#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

double f(double x) { return (x*x - 4*x + 3.5); }	// f(x) = x^2 - 4*x + 3.5

void trapezios (double a, double b, double h);

int main()
{
    double a = 2;
    double b = 6;
    double h = 0.01;

    trapezios(a,b,h);
}

void trapezios(double a, double b, double h)
{
    double integral;
    double n = abs(b-a)/h;
    vector<double>values;

    for(int i = 1; i < n; i++)
    {
        values.push_back(f(a + i*h));
    }
    
    for (int i = 0; i < values.size(); i++)
        integral += values.at(i);

    integral *= 2;

    integral += f(a);
    integral += f(b);

    integral *= (h/2);

    cout << integral;
}