#include <iostream>
#include <math.h>

using namespace std;

bool sravnenie(float x_new[5], float x_old[5]) {
	float E = 0.001;
	for (unsigned i = 0; i < 5; i++)
	{
		if (fabs(x_old[i] - x_new[i]) > E)
			return 0;
	}
	return 1;
}

int main()
{
	float A[5][5] = { {27, 4, -2, 8, 6},
					     {-3, 22, -4, -7, 3},
						 {4, -7, 36, -2, 9},
						 {-2, -8, -9, 28, -4},
	                     {-9, 5, -4, 1, 25} };

	float b[5] = {43, 22, 120, 10, 18};

	float x_old [5] = { 0, 0, 0, 0, 0 }, x_new[5] = { 0, 0, 0, 0, 0 };

	float S = 0;

	//находим x
	do {
		for (unsigned i = 0; i < 5; i++)
		{
			x_old[i] = x_new[i];
		}
		for (unsigned i = 0; i < 5; i++)
		{
			S = b[i];
			for (unsigned j = 0; j < 5; j++)
			{
				if (j == i) continue;
				//находим новые значения x
				S -= A[i][j] * x_old[j];
			}
			x_new[i] = S / A[i][i];
		}
		
	} while (!sravnenie(x_old, x_new));

	for (unsigned i = 0; i < 5; i++)
	{
		cout << x_new[i] << endl;
	}

	return 0;
}
