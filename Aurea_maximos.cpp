#include <iostream>
#include <cmath>
using namespace std;

//Set function
double f(double x) { return pow(2*x+1, 2) -5*cos(10*x);}

int main()
{
    double x1, x2, x3, x4, A, B, max;

    //Set search interval
    x1 = -1;
    x2 = 0;

    //Calculate A and B values
    B = (sqrt(5)-1) / 2;
    A = pow(B,2);

    //Set tolerance interval to 10^-3
    while (abs(x1 - x2) > 0.001)
    {
        //Calculate new values of x3 and x4
        x3 = x1 + A * (x2 - x1);
        x4 = x1 + B * (x2- x1);

        //Get new interval
        if (f(x3) > f(x4))
             x2 = x4;
        else x1 = x3;
    }

    //Compare x1 and x2 and get the smallest value
    if (f(x1) > f(x2))
        max = x1;
    else max = x2;

    //Print results
    cout << "Para x = " << max << "o maximo e " << f(max);
}