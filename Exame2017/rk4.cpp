#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double dy(double t, double y, double z) { return z; }
/*
double dy1(double y, double z, double h) { return h * dy(y, z, h);}

double dy2(double y, double z, double h) {return h * dy(z + h/2.0, y + dy1(y,z,h), h);}

double dy3(double y, double z, double h) {return h * dy(z + h/2.0, y + dy2(y,z,h), h);}

double dy4(double y, double z, double h) {return h * dy(z + h, y + dy3(y,z,h), h);}
*/

double dz(double t, double y, double z) { return 0.5 + t * t + t * z; }
/*
double dz1(double y, double z, double h) { return dz(y, z, h);}

double dz2(double y, double z, double h) {return h * dz(z + h/2.0, y + dz1(y,z,h), h);}

double dz3(double y, double z, double h) {return h * dz(z + h/2.0, y + dz2(y,z,h), h);}

double dz4(double y, double z, double h) {return h * dz(z + h, y + dz3(y,z,h), h);}
*/

int main()
{
    /*
    double h = 0.1;
    double t = 1;
    double y = 0;
    double z = 1;
    double tn, yn, zn;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << nit << "\t" << t << "\t" << y << endl;

        yn = y + (1/6.0) * dy1(y,z,h) + (1/3.0) * dy2(y,z,h) + (1/3.0) * dy3(y,z,h) + (1/6.0) * dy4(y,z,h);

        zn = z + (1/6.0) * dz1(y,z,h) + (1/3.0) * dz2(y,z,h) + (1/3.0) * dz3(y,z,h) + (1/6.0) * dz4(y,z,h);

        t = t + h;

        y = yn;
        z = zn;
    }
    */

    double t = 0, y = 0, z = 1, tn, yn, zn, h = 0.25, dy1, dy2, dy3, dy4, dz1, dz2, dz3, dz4;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << fixed << nit << "\t" << t << "\t" << y << endl;

        dy1 = h * dy(t, y, z);
        dz1 = h * dz(t, y, z);
        dy2 = h * dy(t + h / 2.0, y + dy1 / 2.0, z + dz1 / 2.0);
        dz2 = h * dz(t + h / 2.0, y + dy1 / 2.0, z + dz1 / 2.0);
        dy3 = h * dy(t + h / 2.0, y + dy2 / 2.0, z + dz2 / 2.0);
        dz3 = h * dz(t + h / 2.0, y + dy2 / 2.0, z + dz2 / 2.0);
        dy4 = h * dy(t + h, y + dy3, z + dz3);
        dz4 = h * dz(t + h, y + dy3, z + dz3);

        yn = y + dy1 / 6.0 + dy2 / 3.0 + dy3 / 3.0 + dy4 / 6.0;
        zn = z + dz1 / 6.0 + dz2 / 3.0 + dz3 / 3.0 + dz4 / 6.0;
        tn = t + h;

        y = yn;
        z = zn;
        t = tn;
    }
}