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
	tabl(-0.5, 0.5, 0.1, 1e-5, y);
	cout << endl;
	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(-0.5, 0.5, 0.1, 1e-5, s);
	return 0;
}

void tabl(double a, double b, double h, double eps, uf fun)
{
	int k = 0; double sum;
	for (double x = a; x < b + h / 2; x += h)
	{
		//таки я столкнулся с таким феноменом что -0,1 + 0.1 != 0
		//а равно 2.7755e-17
		if (fabs(x) < 1e-8)
			x = 0;

		sum = fun(x, eps, k);
		cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
	}
}

double y(double x, double eps, int &k)
{
	double a = (1 + x) / (1 - x);
	return 0.25 * log(a) - 0.5 * atan(x);
}

double s(double x, double eps, int &k)
{
	double sum = 0, a = pow(x, 3), b = 3, r = 0;
	k = 1;
	while (fabs(a / b) > eps)
	{
		sum += a / b;
		a *= pow(x, 4);
		b += 4;
		k++;
	}
	return sum;
}