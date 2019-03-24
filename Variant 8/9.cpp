#include <iostream>
#include <math.h>

using namespace std;


double rec(int n,int start);
double noRec(int n);
int main() {

	int n;
	cout << "Enter your mean : " << endl;
	cin >> n;
	double rezult = rec(n, 1);
	double noRecRezult = noRec(n);
	cout << "With rec :\t" << rezult << "\tWithout rec :\t" << noRecRezult  << endl;
	system("pause");
	return 0;
}


double rec(int n, int start) { //start = 1 allways
	if (start == n) {
		return pow(n,1./2);
	}
	else {
		return  pow(start+rec(n,start+1), 1. / 2);
	}
}

double noRec(int n) {
	double rezult = 0,start = 0;
	for (int i = n; i > 0; i--)
	{
		rezult =  pow(rezult + i, 1. / 2);
		
	}
	return rezult;
}
