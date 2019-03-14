#include <iostream>

using namespace std;

int main()
{
	char data[255];

	cin >> data;

	for (int i = 0; i < strlen(data); i++)
	{
		if (data[i] == '.')
		{
			int pos = i - 1;
			int lsize = 0, rsize = 0;

			while ((data[pos] - '0' < 10 && data[pos] - '0' >= 0 || data[pos] == '+' || data[pos] == '-') && pos >= 0)
			{
				lsize++;

				if (data[pos] == '-' || data[pos] == '+')
					break;

				pos--;
			}

			pos = i + 1;

			while (data[pos] - '0' < 10 && data[pos] - '0' >= 0 && pos < strlen(data))
			{
				rsize++;
				pos++;
			}

			if (lsize == 0 || rsize == 0 || (lsize == 1 && (data[i - 1] == '+' || data[i - 1] == '-')))
				continue;

			if (data[pos] == 'e')
			{
				pos++;
				rsize++;
			}
			else
				continue;

			if (data[pos] == '+' || data[pos] == '-')
			{
				pos++;
				rsize++;
			}

			int temp = pos;

			while (data[pos] - '0' < 10 && data[pos] - '0' >= 0 && pos < strlen(data))
			{ 
				pos++;
				rsize++;
			}

			if (pos == temp)
				continue;

			for (pos = i - lsize; pos <= i + rsize; pos++)
				cout << data[pos];

			cout << endl;
		}
	}

	return 0;
}