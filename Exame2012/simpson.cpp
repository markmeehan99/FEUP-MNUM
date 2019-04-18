#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {return exp(1.5*x);}

double simp(double h)
{
    double a = 2.5, b = 3, integral = 0;

    for (double i = a + h; i < b; i = i + 2*h)
        integral += 4 * f(i);
    
    for (double i = a + h*2; i < b; i = i + 2*h)
        integral += 2 * f(i);
    
    integral += f(a);
    integral += f(b);
    
    integral *= h/3;

    return integral;
}

int main()
{
    cout << setprecision(5) << fixed;
    cout << "S:\t\t" << simp(0.125) << endl << "S':\t\t" << simp(0.125/2.0) << endl << "S'':\t\t" << simp(0.125/4) << endl;

    cout << "QC:\t\t" << (simp(0.125/2) - simp(0.125)) / (simp(0.125/4.0) - simp(0.125/2.0)) << endl;
    cout << "Erro:\t\t" << (simp(0.125/4) - simp(0.125/2)) / 15.0 << endl;
}
