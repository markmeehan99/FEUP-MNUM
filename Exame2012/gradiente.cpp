#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) { return 3 * x * x - x * y + 11 * y + y * y - 8 * x; }

double fx(double x, double y) { return 6 * x - y - 8; }

double fy(double x, double y) { return -x + 11 + 2 * y; }

int main()
{
    double x = 2, y = 2, h = 0.5, xn = 0, yn = 0;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << fixed << nit << "\t" << x << "\t" << y << "\t" << f(x, y) << "\t" << fx(x, y) << "\t" << fy(x, y) << endl;

        xn = x - h * fx(x, y);
        yn = y - h * fy(x, y);

        if (f(xn, yn) < f(x, y))
        {
            x = xn;
            y = yn;
            h *= 2;
        }
        else
        {
            h /= 2;
            xn = x;
            yn = y;
        }
    }
}