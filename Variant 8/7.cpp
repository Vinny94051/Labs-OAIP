#include <iostream>

using namespace std;

struct BookData
{
	int id;
	char author[50];
	char title[50];
	int year;
	char publisher[50];
	int page_cnt;
};


int main()
{
	int n;
	cout << "Enter number of books:";
	cin >> n;

	BookData * data = new BookData[n];


	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << endl;

		cout << "Enter id:";
		cin >> data[i].id;
		cin.ignore(1, '\n');
		cout << "Enter author:";
		cin.getline(data[i].author, 50);
		cout << "Enter title:";
		cin.getline(data[i].title, 50);
		cout << "Enter year:";
		cin >> data[i].year;
		cin.ignore(1, '\n');
		cout << "Enter publisher:";
		cin.getline(data[i].publisher, 50);
		cout << "Enter number of pages:";
		cin >> data[i].page_cnt;
	}

	int year;
	cout << "Enter year to filter:";
	cin >> year;

	BookData * filtered_data = new BookData[n];
	int filtered_cnt = 0;

	//filter
	for (int i = 0; i < n; i++)
	{
		if (data[i].year > year)
		{
			filtered_data[filtered_cnt++] = data[i];
		}
	}

	//sort
	for (int i = filtered_cnt - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (strcmp(filtered_data[j].author, filtered_data[j + 1].author) > 0)
			{
				BookData temp = filtered_data[j];
				filtered_data[j] = filtered_data[j + 1];
				filtered_data[j + 1] = temp;
			}
		}
	}

	//print result

	for (int i = 0; i < filtered_cnt; i++)
	{
		cout << i + 1 << endl;

		//cin.ignore(1, '\n');

		cout << "Id: " << filtered_data[i].id << endl;
		cout << "Author: " << filtered_data[i].author << endl;
		cout << "Title: " << filtered_data[i].title << endl;
		cout << "Year: " << filtered_data[i].year << endl;
		cout << "Publisher: " << filtered_data[i].publisher << endl;
		cout << "Number of pages:" << filtered_data[i].page_cnt << endl;
	}

	return 0;
}