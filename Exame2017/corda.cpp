#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return pow(x, 7) - 0.5 * x - 1; }

int main()
{
    double a = 1, b = 1.5;

    for (int nit = 0; nit < 4; nit++)
    {
        double w = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << fixed << a << "\t" << b << "\t" << w << endl;

        if (f(w) * f(a) < 0)
            b = w;
        else
            a = w;
    }
}