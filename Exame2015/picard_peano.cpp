#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {return 2* log(2*x);}

int main()
{
    double x = 0.9;

    for (int nit = 0; nit < 3; nit++)
    {
        cout << x << endl;

        x = f(x);
    }
}