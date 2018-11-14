#include <iostream>
#include <vector>
using namespace std;

double main()
{
    vector<vector<double>> A = {{ 3 , 2 , 5 , 22 },
			            	 { 1 , -5 , 1 , -4 },
		            		 { 2 , 1 , -2 , 1 }};

    double lines = A.size();
    double cols = A[0].size();

    for(double diag = 1; diag <= lines; diag++)
    {
        for(double col = diag + 1; col < cols; col++)
        {
            A[diag][col] = A[diag][col] / A[diag][diag];
        }

        A[diag][diag] = 1;
    
        for(double line = diag + 1; line <= lines; line++)
        {
            for(double col = diag + 1; col < cols; col++)
                A[line][col] = A[diag][col] * A[line][diag] - A[line][col];
            
            A[line][diag] = 0;
        }
    }

    return 0;
}