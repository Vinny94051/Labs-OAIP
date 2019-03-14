#include <iostream>

using namespace std;

int main()
{
	char data[255];

	cin >> data;

	int start = 0, max_size = INT_MIN;
	char ch_type = data[0];

	for (int i = 0; i < strlen(data); i++)
	{
		if (data[i] != ch_type)
		{
			int size = i - start;

			if (size > max_size)
			{
				max_size = size;
			}

			start = i;
			ch_type = data[i];
		}
	}

	if (strlen(data) - start > max_size)
	{
		max_size = strlen(data) - start;
	}

	cout << max_size;
}