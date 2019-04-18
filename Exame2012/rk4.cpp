#include <iostream>
#include <cmath>
using namespace std;

double dy(double t, double y, double z) { return z; }

double dz(double t, double y, double z) { return 0.5 + t * t + t * z; }

double dy1(double t, double y, double z, double h) { return h * dy(t, y, z); }

double dz1(double t, double y, double z, double h) { return h * dz(t, y, z); }

double dy2(double t, double y, double z, double h) { return h * dy(t + h / 2.0, y + dy1(t, y, z, h) / 2.0, z + dz1(t, y, z, h) / 2.0); }

double dz2(double t, double y, double z, double h) { return h * dz(t + h / 2.0, y + dy1(t, y, z, h) / 2.0, z + dz1(t, y, z, h) / 2.0); }

double dy3(double t, double y, double z, double h) { return h * dy(t + h / 2.0, y + dy2(t, y, z, h) / 2.0, z + dz2(t, y, z, h) / 2.0); }

double dz3(double t, double y, double z, double h) { return h * dz(t + h / 2.0, y + dy2(t, y, z, h) / 2.0, z + dz2(t, y, z, h) / 2.0); }

double dy4(double t, double y, double z, double h) { return h * dy(t + h, y + dy3(t, y, z, h), z + dz3(t, y, z, h)); }

double dz4(double t, double y, double z, double h) { return h * dz(t + h, y + dy3(t, y, z, h), z + dz3(t, y, z, h)); }

int main()
{
    double h = 0.25, t = 0, y = 0, z = 1;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << nit << "\t\t" << t << "\t\t" << y << endl;

        y = y + (1/6.0) * dy1(t,y,z, h) + (1/3.0) * dy2(t,y,z, h) + (1/3.0) * dy3(t,y,z,h) + (1/6.0) * dy4(t,y,z,h);
        z = z + (1/6.0) * dz1(t,y,z, h) + (1/3.0) * dz2(t,y,z, h) + (1/3.0) * dz3(t,y,z,h) + (1/6.0) * dz4(t,y,z,h);
        t = t + h;
    }
}