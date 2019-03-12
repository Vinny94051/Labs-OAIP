#include <iostream>

using namespace std;

struct SpData
{
	char country[50];
	char team_name[50];
	char fio[50];
	int id;
	int age;
	int height;
	int weight;
};


int main()
{
	int n, teams_cnt = 0;
	cout << "Enter number of people:";
	cin >> n;

	SpData data[1000];
	char* teams[1000];
	int ages[1000], cnt[1000];


	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << endl;

		cin.ignore(1, '\n');

		cout << "Enter country name: ";
		cin.getline(data[i].country, 50);
		cout << "Enter team name: ";
		cin.getline(data[i].team_name, 50);
		cout << "Enter full name: ";
		cin.getline(data[i].fio, 50);
		cout << "Enter ID: ";
		cin >> data[i].id;
		cout << "Enter age: ";
		cin >> data[i].age;
		cout << "Enter height: ";
		cin >> data[i].height;
		cout << "Enter weight: ";
		cin >> data[i].weight;

		bool flag = true;

		for (int j = 0; j < teams_cnt; j++)
		{
			if (strcmp(data[i].team_name, teams[j]) == 0)
			{
				flag = false;
				ages[j] += data[i].age;
				cnt[j]++;
				break;
			}
		}

		if (flag)
		{
			teams[teams_cnt] = data[i].team_name;
			ages[teams_cnt] = data[i].age;
			cnt[teams_cnt]++;
			teams_cnt++;
		}
	}

	int min_ind = 0;
	double min = 1000;

	for (int i = 0; i < teams_cnt; i++)
	{
		double average = ages[i] / (double)cnt[i];

		if (average < min)
		{
			min = average;
			min_ind = i;
		}
	}

	cout << "Team name: " << teams[min_ind] << endl;
	cout << "Age: " << min;
	cout << "Players: " << endl;

	for (int i = 0; i < n; i++)
	{
		if (strcmp(data[i].team_name, teams[min_ind]) == 0)
		{
			cout << "Country: " << data[i].country << endl;
			cout << "Team: " << data[i].team_name << endl;
			cout << "Full name: " << data[i].fio << endl;
			cout << "ID: " << data[i].id << endl;
			cout << "Age: " << data[i].age << endl;
			cout << "Height: " << data[i].height << endl;
			cout << "Weight: " << data[i].weight << endl;
		}
	}

	return 0;
}