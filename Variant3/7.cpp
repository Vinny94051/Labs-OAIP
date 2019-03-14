#include <iostream>

using namespace std;

struct StudentData
{
	char fio[50];
	int group;
	int average_assessment;
	int income;
};


int main()
{
	int n, min_pay;
	cout << "Enter number of people:";
	cin >> n;
	cout << "Enter minimal pay:";
	cin >> min_pay;

	StudentData first[1000], second[1000];
	int first_size = 0, second_size = 0;


	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << endl;

		StudentData temp;

		cin.ignore(1, '\n');

		cout << "Enter full name: ";
		cin.getline(temp.fio, 50);
		cout << "Enter group: ";
		cin >> temp.group;
		cout << "Enter average assessment: ";
		cin >> temp.average_assessment;
		cout << "Enter income: ";
		cin >> temp.income;

		if (temp.income < 2 * min_pay)
			first[first_size++] = temp;
		else
			second[second_size++] = temp;
	}

	for (int i = first_size - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (first[j].average_assessment < first[j + 1].average_assessment)
			{
				StudentData temp = first[j];
				first[j] = first[j + 1];
				first[j + 1] = temp;
			}
		}
	}

	for (int i = second_size - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (second[j].average_assessment < second[j + 1].average_assessment)
			{
				StudentData temp = second[j];
				second[j] = second[j + 1];
				second[j + 1] = temp;
			}
		}
	}

	cout << endl;

	for (int i = 0; i < first_size; i++)
	{
		cout << "Full name: " << first[i].fio << endl;
		cout << "Group: " << first[i].group << endl;
		cout << "Average assessment: " << first[i].average_assessment << endl;
		cout << "Income: " << first[i].income << endl;
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < second_size; i++)
	{
		cout << "Full name: " << second[i].fio << endl;
		cout << "Group: " << second[i].group << endl;
		cout << "Average assessment: " << second[i].average_assessment << endl;
		cout << "Income: " << second[i].income << endl;
		cout << endl;
	}

	return 0;
}