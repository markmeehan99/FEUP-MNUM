#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) { return (x*x - x - 1.2);}

void bissecao (double ax, double bx)
{
    double a = ax;
    double b = bx;
    double m;
    int n = 0;

    while (abs(b-a) > pow(10,-1))
    {
        m = (b+a)/2;

        if (f(a) * f(m) < 0)
            b = m;
        else a = m;
        n++;
    }

    cout << fixed << setprecision(4) << "n: " << n << endl << "m: " << m << endl << endl;
}

int main()
{
    double a0 = 1;
    double b0 = 2;

    bissecao(a0,b0);

    return 1;
    
}