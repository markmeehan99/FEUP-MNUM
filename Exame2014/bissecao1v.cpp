#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {return pow(x,3)-10*sin(x)+2.8;}


int main()
{
    double a = 1.5, b = 4.2, m = 0;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << a << "\t" << b << endl;

        m = abs(b+a) / 2;

        if (f(m) * f(a) < 0)
            b = m;
        else
            a = m; 
    }
}
