#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double dy(double y, double t, double z) { return z; }

double dz(double y, double t, double z) { return 0.5 + pow(t, 2) + t * z; }

int main()
{
    double h = 0.25;
    double t = 0;
    double y = 0;
    double z = 1;
    double tn, yn, zn;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << nit << "\t" << t << "\t" << y << endl;

        yn = y + h * dy(y, t, z);
        zn = z + h * dz(y, t, z);
        tn = t + h;

        y = yn;
        z = zn;
        t = tn;
    }
}
