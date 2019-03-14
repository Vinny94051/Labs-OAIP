#include <iostream>

using namespace std;

int main()
{
	int k;

	cout << "Input k:" << endl;
	cin >> k;

	char arr[100000];

	cout << "Input array:" << endl;
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	int new_size = k;

	for (int i = 0; i < new_size; i++)
	{
		for (int j = i + 1; j < new_size; j++)
		{
			if (arr[i] == arr[j])
			{
				//cout << j << " " << arr[j] << endl;

				for (int k = j + 1; k < new_size; k++)
				{
					arr[k - 1] = arr[k];
				}

				new_size--;
				j--;

				/*for (int i = 0; i < new_size; i++)
					cout << arr[i] << " ";

				cout << endl;
				cout << new_size << endl;
				cout << "-------------------------" << endl;*/
			}
		}
	}

	for (int i = 0; i < new_size; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}