#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) { return (3*x + sin(x) - exp(x));}

void corda (double a0, double b0, int nit)
{
    double a = a0;
    double b = b0;
    double m;

    for(int i =0; i < nit; i++)
    {
        m = ( a*f(b) - b*f(a) ) / ( f(b) - f(a) );

        if (f(m) * f(a) > 0)
			a = m;
		else
			b = m;
    }

    cout << fixed << setprecision(6) << "m: " << m << endl << endl;

}

int main()
{
    double a0 = 0;
    double b0 = 1;
    int nit = 10;

    corda(a0, b0, 4);

    return 1;
    
}