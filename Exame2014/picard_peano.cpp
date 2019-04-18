#include <iostream>
#include <cmath>
using namespace std;


double f(double x) {return 2*log(2*x);}

int main()
{
    double x = 1.1;

    for (int nit = 0; nit < 2; nit++)
    {
        cout << x << endl;

        x = f(x);
    }
}