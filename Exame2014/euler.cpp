#include <iostream>
#include <cmath>
using namespace std;

double dy(double y, double t) { return y / (t - 1); }

int main()
{
    double h = 0.25, t = 2, y = 2;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << fixed << nit << "\t" << t << "\t" << y << endl;

        y = y + h * dy(y, t);
        t += h;
    }
}
