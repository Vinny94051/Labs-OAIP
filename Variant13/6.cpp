#include <iostream>

using namespace std;

int main()
{
	char data[255];
	int k;

	cout << "str: ";
	cin.getline(data, 255);
	cout << "k: ";
	cin >> k;

	while (data[k] != ' ' && k > 0)
		k--;

	for (int i = 0; i < k; i++)
		cout << data[i];

	cout << endl;

	if (data[k] == ' ')
		k++;

	for (int i = k; i < strlen(data); i++)
		cout << data[i];
}