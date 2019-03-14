#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

typedef double(*uf)(double, double, int &);
void tabl(double, double, double, double, uf);
double y(double, double, int &);
double s(double, double, int &);

int main()
{
	cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
	tabl(-0.9, 0.9, 0.1, 0.001, y);
	cout << endl;
	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(-0.9, 0.9, 0.1, 0.001, s);
	return 0;
}

void tabl(double a, double b, double h, double eps, uf fun)
{
	int k = 0; double sum;
	for (double x = a; x < b + h / 2; x += h)
	{
		sum = fun(x, eps, k);
		cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
	}
}

double y(double x, double eps, int &k)
{
	return pow(1 + x, 1 / 3.0);
}

double s(double x, double eps, int &k)
{
	double a, c, sum;
	sum = a = c = 1;
	k = 1;
	while (fabs(a) > eps)
	{
		c = ((3 * k - 4) * x) / (3 * k);
		a *= -c;
		sum += a;
		k++;
	}
	return sum;
}