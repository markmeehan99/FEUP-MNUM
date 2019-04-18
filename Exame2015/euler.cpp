#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double T, double t) {return -0.25 * (T - 37);}

int main()
{
    double T = 3, t = 5, h = 0.4;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << T << endl;

        T = T + h * f(T,t);
        t = t + h;
    }
}
