#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct WorkPlace
{
	string product_name;
	int product_num;
	int work_place_num;
};

int main()
{

	int size;
	cout << "Enter numbers of work places: " << endl;
	cin >> size;

	WorkPlace *ptrObjects = new WorkPlace[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the workplace num : " << endl;
		cin >> ptrObjects[i].work_place_num;
		cout << "Enter the product_name of " << ptrObjects[i].work_place_num << " work place : " << endl;
		cin.ignore();
		getline(cin, ptrObjects[i].product_name);
		cout << "Enter number of products for " << ptrObjects[i].work_place_num << " work plase : " << endl;
		cin >> ptrObjects[i].product_num;
		cout << endl << endl;
	}

	cout << "Enter work place number : " << endl;
	int num;
	cin >> num;
	cout << endl;

	cout << "What product u want to see : " << endl;
	string prod_name;
	cin.ignore();
	getline(cin,prod_name);



	for (int i = 0; i < size; i++)
	{
		string buf = ptrObjects[i].product_name;
		if (num == ptrObjects[i].work_place_num && buf == prod_name)
		{
	
			cout << endl <<
				"Numbers of product is : " << ptrObjects[i].product_num << endl;
		
		}
	}

	system("pause");
	return 0;
}