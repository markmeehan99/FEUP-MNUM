#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x, double y) { return (pow(x,3));}

void euler (double x0, double y0, double h, int nit);

int main()
{
    double x0 = 0;
    double y0 = 0;
    double h = 0.01;
    int nit = 4;

    euler(x0,y0,h,nit);
}

void euler (double x0, double y0, double h, int nit)
{
    double x = x0;
    double y = y0;

    for (unsigned int i = 0; i < nit; i++)
    {
        y += h*f(x,y);
        x += h;
    }

    cout << "n: " << nit << endl << "x: " << x << endl << "y: " << y << endl;
}