#include <iostream>
#include <math.h>

using namespace std;

int fact(int n);
int main() {

	double a = 0.1, b = 1, x;
	int n = 5;

	cout << "Enter x" << endl;
	cin >> x;

	double step = (b - a) / 10;

	cout << "Y(x)\tS(x)" << endl;
	double el = 0, delta = 1;
	for (double i = 0; i < n; i += step)
	{
		cout << ((x*x) / 4 + x / 2 + 1) * pow(exp(x), x / 2) << " " << "=\t";
		
		delta *= x * (pow((fact(n - 1)), (n - 1))) / (2 * pow(fact(n), n));
		el += delta;

		cout << el << endl;

	}

	

	system("pause");
}

int fact(int n) {
	if (n == 1) {
		return n;
	}
	else {
		return n * (fact(n - 1));
	}
}