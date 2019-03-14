#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	char data[255];

	cin >> data;

	int start = 0, min_size = INT_MAX, min_start = 0;
	char ch_type = data[0];

	for (int i = 0; i < strlen(data); i++)
	{
		if (data[i] != ch_type)
		{
			int size = i - start;

			if (size < min_size)
			{
				min_start = start;
				min_size = size;
			}

			start = i;
			ch_type = data[i];
		}
	}

	if (strlen(data) - start < min_size)
	{
		min_start = start;
		min_size = strlen(data) - start;
	}

	for (int i = min_start; i < min_start + min_size; i++)
		cout << data[i];
}