#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a = -2, b = -0.1;
	int n = 160;

	double step = (b - a) / 10;

	cout << "Y(x)         S(x)" << endl;

	for (double x = a; x <= b; x += step)
	{
		cout << log(1 / (2 + 2 * x + x * x)) << "  ";
		double sum = 0, u = 1, d = 0;

		for (int i = 0; i < n; i++)
		{
			u *= -pow(1 + x, 2);
			d += 1;

			sum += u / d;
		}

		cout << sum << endl;
	}

	return 0;
}