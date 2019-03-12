#include <iostream>
#include <math.h>

using namespace std;

double sqrt_t(double a, int n)
{
	if (n == 0)
	{
		return 0.5 * (1 + a);
	}
	else
	{
		double next = sqrt_t(a, n - 1);
		return 0.5 * (next + a / next);
	}	
}

int main()
{
	double a;
	cin >> a;

	cout << "sqrt(a) = " << sqrt_t(a, 100);
	return 0;
}