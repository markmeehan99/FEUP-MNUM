#include <iostream>
#include <cmath>
using namespace std;

double dy(double t, double y, double z) { return z; }

double dz(double t, double y, double z) { return 0.5 + t * t + t * z; }

int main()
{
    double h = 0.25, t = 0, y = 0, z = 1, yn, zn, tn;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << fixed << nit << "\t" << t << "\t" << y << endl;
        
        yn = y + h * dy(t, y, z);
        zn = z + h * dz(t, y, z);
        tn = t + h;

        y = yn;
        z = zn;
        t = tn;
    }
}