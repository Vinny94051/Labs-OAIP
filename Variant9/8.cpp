#include <iostream>
#include <math.h>

using namespace std;

const double PI = 3.14;
double Y_x(double a);
double S_x(double k,double x);
int main() {

	double x,k;
	cout << "Enter k,x : " << endl;
	cin >> k >> x;
		
	for (int i = 0; i < k; i++)
	{
		cout << Y_x(x) << "\t\t" << S_x(k, x + i) << endl;
		
		if (k - 1 == i) {
			cout << "We need " << i+1 << " iterations." << endl;
		}
	}

	

	system("pause");
}




double Y_x(double a) {

	return (PI*(PI - 2 * fabs(a))) / 8;
}

double S_x(double k, double x) {

	return (cos(2 * k - 1)*x) / pow(2*k - 1,2);
}