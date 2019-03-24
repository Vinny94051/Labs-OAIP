#include <iostream>
#include <math.h>
#include <ctime>
#include <string.h>


using namespace std;


int main() {
	srand(time(NULL));
	
	cout << "Enter k" << endl;
	int k;
	cin >> k;

	int *a = new int[k];

	for (int i = 0; i < k; i++)
	{
		a[i] = rand() % 10 - 3;
		cout << a[i] << " ";
	}
	cout << endl;

	int posistive_size = 1, negative_size = 1;
	int *positiveA = new int[posistive_size];
	int *negativeA = new int[negative_size];

	for (int i = 0; i < k; i++)
	{
		if (a[i] < 0) {
			negativeA[negative_size - 1] = a[i];
			negative_size++;
		}
		else {
		 positiveA[posistive_size-1] = a[i];
			posistive_size++;
		}
	}

	for (int i = 0; i < negative_size; i++)
	{
		a[i] = negativeA[i];
	}

	int counter = 0;
	for (int i = negative_size-1; i < k; i++)
	{
		a[i] = positiveA[counter];
		counter++;
	}

	for (int i = 0; i < k; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}
