#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a = 0.1, b = 1;
	int n = 160;

	double step = (b - a) / 10;

	cout << "Y(x)         S(x)" << endl;

	for (double x = a; x <= b; x += step)
	{
		cout << sin(x) << "  ";
		double sum = 0, a = x;

		for (int i = 1; i < n; i++)
		{
			sum += a;
			a *= -x * x / (2 * i * (2 * i + 1));
		}

		cout << sum << endl;
	}

	return 0;
}