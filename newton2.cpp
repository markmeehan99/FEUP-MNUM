#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//double f(double x) { return (exp(x) - (x*x) + 3*x - 2);}
double f(double x, double y) { return (-x*x + 1 - y);}

double dfx(double x, double y) {return (-2*x - 1);}

double dfy(double x, double y) { return -1;}

double g(double x, double y) { return (-y + 0.7 + x);}

double dgx(double x, double y) { return 1;}

double dgy(double x, double y) { return -1;}


void bissecao(double a0, double b0);
void newton(double guess);
void corda(double a0, double b0, int nit);
void picardp(double guess);
void newton2(double x0, double y0, int nit);

int main()
{
    double x0 = 0;
    double y0 = 1;
    int nit = 10;

    newton2(x0, y0, nit);
    return 1;
    
}


void newton2(double x0, double y0, int nit)
{
    double x = x0;
    double y = y0;

    double xn;
    double yn;
    double jacobian;
    int n = 0;

    do
    {
        x = xn;
        y = yn;

        jacobian = dfx(x,y)*dgy(x,y) - dgx(x,y) * dfy(x,y);

        xn = x - ((f(x,y) * dgy(x,y) - g(x,y) * dfy(x,y)) / jacobian);
        yn = y - ((g(x,y) * dfx(x,y) - f(x,y) * dgx(x,y)) / jacobian);

        n++;
    } while (abs(xn - x) > pow(10, -3)) ;

cout << fixed << setprecision(5) << "n: " << n << endl << "xn: " << xn  << endl << "yn: " << yn << "\n\n";
}