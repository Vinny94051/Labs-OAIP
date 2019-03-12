#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a = 0.1, b = 1;
	int n = 120;

	double step = (b - a) / 10;

	cout << "Y(x)         S(x)" << endl;

	for (double x = a; x <= b; x += step)
	{
		cout << (1 + x * x) / 2 * atan(x) - x / 2 << "  ";
		double sum = 0, a = -x, b = -1.0;

		for (int i = 0; i < n; i++)
		{
			a *= x * x * -1;
			b += 8 * i + 4;

			sum += a / b;
		}

		cout << sum << endl;
	}

	return 0;
}