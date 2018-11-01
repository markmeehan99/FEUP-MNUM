#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {return (exp(x) - x*x +3*x - 2);}

double df(double x) {return (exp(x) - 2*x + 3);}

void newton (double guess)
{
    double xn = guess;
    double x;
    int n = 0;

    do
    {
        x = xn;
        xn = x - (f(x) / df(x));
        n++;
    } while ((xn - x) > (5 * pow(10,-4)));

    cout << fixed << setprecision(4) << "n: " << n << endl << "xn: " << xn << endl;
}

int main()
{
    double guess = 0.1;

    newton(guess);

    return 1;
    
}