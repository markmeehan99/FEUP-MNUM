#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;

double f(double x, double y) { return (x + y); }

double rk2(double h)
{
    double x, y, xn = 0, yn = 0;

    for (;xn<1.3999;)
    {
        x = xn;
        y = yn;
        xn = x + h;
        yn = y + h * f(x + h/2, y + h/2 * f(x, y));
    }

    cout << "yn = " << yn << endl;
    
    return yn;
}


int main()
{
    rk2 (10);

    return 0;
}