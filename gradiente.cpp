#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {return pow(y,2) - 2*x*y - 6*y + 2*pow(x,2) + 12;}

double dx(double x, double y) {return -2*y + 4*x;}

double dy(double x, double y) {return 2*y - 2*x - 6;}

int main()
{
    double x_ant, y_ant, x = 1, y = 1, h = 1;
    
	x_ant = x;
	y_ant = y;

	x = x - h * dx(x_ant, y_ant);
	y = y - h * dy(x_ant, y_ant);

    while (abs(x - x_ant) > 0.001 || abs(y - y_ant) > 0.001) 
    {
		if (f(x, y) < f(x_ant, y_ant))
			h *= 2;
        else h /= 2;

		x_ant = x;
		y_ant = y;

		x = x - h * dx(x_ant, y_ant);
		y = y - h * dy(x_ant, y_ant);
    }

    cout << "Para x = " << x << " minimo = " << f(x, y);
}
