#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int k, n;

	cout << "Enter k, n:" << endl;
	cin >> k >> n;

	int arr[100000]; // double ?

	for (int i = 0; i < k; i++)
		cin >> arr[i];

	for (int i = k - 1; i >= 0; i--)
	{
		arr[i + n] = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i + k];
	}

	for (int i = 0; i < k; i++)
		cout << arr[i] << " ";

	return 0;
}