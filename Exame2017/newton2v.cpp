#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) { return (x * x - y - 2); }

double g(double x, double y) { return (-x + y * y - 3); }

double fx(double x, double y) { return 2 * x; }

double fy(double x, double y) { return -1; }

double gx(double x, double y) { return -1; }

double gy(double x, double y) { return 2 * y; }

int main()
{
    double x = 0.8;
    double y = 1.5;

    double xn, yn;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << x << "\t" << y << endl;

        xn = x - (f(x, y) * gy(x, y) - g(x, y) * fy(x, y)) / (fx(x, y) * gy(x, y) - gx(x, y) * fy(x, y));
        yn = y - (g(x, y) * fx(x, y) - f(x, y) * gx(x, y)) / (fx(x, y) * gy(x, y) - gx(x, y) * fy(x, y));

        x = xn;
        y = yn;
    }
}
