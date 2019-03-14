#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, f;
	int code;

	cout << "Chose f(x): 0 - sh(x), 1 - x^2, 2 - exp(x)" << endl;
	cin >> code;

	cout << "Enter x, y:" << endl;
	cin >> x >> y;

	switch (code)
	{
	case 0:
		f = sinh(x);
		break;
	case 1:
		f = x * x;
		break;
	case 2:
		f = exp(x);
		break;
	default:
		cout << "Неверный ввод!";
		return 0;
	}

	if (x / y < 0)
	{
		cout << pow(f * f + y, 3);
	}
	else if (x / y > 0)
	{
		cout << log(fabs(f / y)) + x / y;
	}
	else
	{
		cout << pow(fabs(sin(y)), 1 / 3.);
	}

}