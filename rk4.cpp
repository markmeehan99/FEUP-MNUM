#include <iostream>
using namespace std;

double f(double x, double y) { return y;}

void rk4(double x0, double y0, double h, unsigned int nit)
{
    double x = x0, y = y0, k1, k2, k3, k4;

    for (unsigned int i = 0; i < nit; i++)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);

        y = y + double(1/6) * (k1 + 2*k2 + 2*k3 + k4);
        x += h;

        cout << "i: " << i << "\t" << "x: " << x << "\t" << "y: " << y << "\n";
    }
}

int main()
{
    const double x0 = 0;
	const double y0 = 1;
    const double h = 0.1;
	const unsigned int nit = 100;
    rk4(x0, y0, h, nit);
}