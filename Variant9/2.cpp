#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
	cout << "Choose one : sh(x) - press 1, x^2 - press 2 or e^x - press 3" << endl;
	int choose;
	cin >> choose;

	double f_x,x,y;

	cout << "Enter x and y" << endl;
	cin >> x >> y;

	switch (choose)
	{
	case 1: 
		f_x = sinh(x);
		break;
	case 2: 
		f_x = pow(x, 2);
		break;
	case 3 : 
		f_x = pow(exp(2), 2);
		break;
	default:
		cout << "We have only 3 function;" << endl;
		break;
	}

	double l;

	if (x > fabs(y)) 
	{
		l = (2 * pow(f_x, 3)) + (3 * pow(y, 2));
	}
	else if (x > 3 && fabs(y) > x) 
	{
		l = fabs(f_x - y);
	}
	else 
	{
		l = fabs(pow(f_x - y, 1 / 3.));
	}
	cout << "The l is : " << l << endl;
	system("pause");
	return 0;
}