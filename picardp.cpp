#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) { return (x*x - 0.2);}

void picardp(double guess)
{
    double xn = guess;
    double x;

    do
    {
        x = xn;
        xn = f(x);
    } while (abs(xn - x) > pow(10,-7));

    cout << fixed << setprecision(4) << "xn: " << xn << endl;
}

int main()
{
    double guess = 0;

    picardp(guess);
    return 1;
    
}