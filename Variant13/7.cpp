#include <iostream>

using namespace std;

struct TrainData
{
	int day;
	int destination;
	int time;
	int tickets;
};


int main()
{
	int n;
	cout << "Enter number of trains:";
	cin >> n;

	TrainData data[1000];

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << endl;

		cin.ignore(1, '\n');

		cout << "Enter destination: ";
		cin >> data[i].destination;
		cout << "Enter day: ";
		cin >> data[i].day;
		cout << "Enter time: ";
		cin >> data[i].time; // тут время вводится в 24 часовом формате
		cout << "Enter tickets: ";
		cin >> data[i].tickets;
	}

	int m, N, k, t;
	cout << "m, N, k, t(pm): ";// а тут pm
	cin >> m >> N >> k >> t;
	t += 12;

	for (int i = 0; i < n; i++)
	{
		if (data[i].destination == N && data[i].tickets >= m && data[i].day == k && data[i].time <= t)
		{
			cout << t;
			return 0;
		}
	}

	cout << "imposible";

	return 0;
}