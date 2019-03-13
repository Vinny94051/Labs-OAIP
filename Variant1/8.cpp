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
	tabl(-0.9, 0.9, 0.1, 1e-4, y);
	cout << endl;
	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(-0.9, 0.9, 0.1, 1e-4, s);
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
	return 0.5 * log((1 + x) / (1 - x));
}

double s(double x, double eps, int &k)
{
	double a = x, b = 1, sum = 0;
	k = 1;
	
	while (fabs(a / b) >= eps)
	{
		sum += a / b;
		b += 2;
		a *= pow(x, 2);
		k++;
	}
	return sum;
}