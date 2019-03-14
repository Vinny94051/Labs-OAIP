#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int k;

	cout << "Enter k:" << endl;
	cin >> k;

	int arr[100000];

	for (int i = 0; i < k; i++)
		cin >> arr[i];

	int max_val = 0, max_cnt = 0;

	for (int i = 0; i < k; i++)
	{
		int cnt = 0;

		for (int j = i; j < k; j++)
			if (arr[i] == arr[j])
				cnt++;

		if (cnt > max_cnt)
		{
			max_cnt = cnt;
			max_val = arr[i];
		}
	}

	cout << max_val;

	return 0;
}