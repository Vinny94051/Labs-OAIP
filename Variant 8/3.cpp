#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a = 0.1, b = 1;
	int n = 100;

	double step = (b - a) / 10;

	cout << "Y(x)         S(x)" << endl;

	for (double x = a; x <= b; x += step)
	{
		cout << exp(2 * x) << "  ";
		double sum = 1, a = 1, b = 1;

		for (int i = 1; i < n; i++)
		{
			a *= 2 * x;
			b *= i;

			sum += a / b;
		}

		cout << sum << endl;
	}

	return 0;
}