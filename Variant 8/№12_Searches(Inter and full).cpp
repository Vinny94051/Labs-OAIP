#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

struct employee {
	int dateOfstart;
	string name;
};

int fullBustSearch(employee *list, int dateOfStart, int listSize ) {
	for (int i = 0; i < listSize; i++)
	{
		if (list[i].dateOfstart == dateOfStart) {
			cout << "\nHis number is " << i << endl;
			return i;
		}
	}
	cout << "We have no this employee" << endl;
	return 0;
}

int interpolationSearch(employee *list, int dateOfStart, int listSize) {
	int low = 0;
	int high = listSize - 1;
	int pivot;
	
	int counter = 0;
	while (low < high) {
		if (counter > listSize) { 
			cout << "We have no it" << endl;
			return 0; }
		if (list[low].dateOfstart == list[high].dateOfstart) {
			if (list[low].dateOfstart == dateOfStart) { 
				cout << "his number is : " << low << endl;
				return low;
			}
		}
		

		pivot = low + (high - low)*(dateOfStart - list[low].dateOfstart) / (list[high].dateOfstart - list[low].dateOfstart);

		if (list[pivot].dateOfstart == dateOfStart) { 
			cout << "\nHis number is " << pivot << endl;
			return pivot; 
		}
		else {
			if (dateOfStart > list[pivot].dateOfstart) { 
				low = pivot + 1;
			}
			else if (dateOfStart < list[pivot].dateOfstart) { 
				high = pivot - 1;
			}
		}
		counter++;
	}
	cout << "We have no this employee" << endl;
}

void stupidSort(employee *array, int size);
void printEmployee(employee emp);
void printList(employee *list, int size);
int main() {
	srand(time(NULL));
	const int SIZE = 15;
	employee *employeesList = new employee[SIZE];
	
	
	for (int i = 0; i < SIZE; i++)
	{
		employeesList[i].dateOfstart = rand() % 20 + 1965;
		employeesList[i].name = "Random name";
	}

	stupidSort(employeesList, SIZE);
	cout << endl;
	printList(employeesList, SIZE);
	cout << "\nInter : \n";
	interpolationSearch(employeesList, 1975, SIZE);
	cout << "\nFull : \n";
	fullBustSearch(employeesList, 1975, SIZE);
	
	system("pause");
	return 0;
}


void stupidSort(employee * array, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if (array[i].dateOfstart > array[i + 1].dateOfstart) {
			swap(array[i], array[i + 1]);
			i = -1;
		}
	}
}

void printEmployee(employee emp)
{
	cout << "The name of worker is : " << " ";
	for (int i = 0; i < emp.name.size(); i++)
	{
		cout << emp.name[i];
	}
	cout << "\t";
	cout << "The date of start is : " << emp.dateOfstart << endl;
}

void printList(employee * list, int size)
{
	for (int i = 0; i < size; i++)
	{
		printEmployee(list[i]);
	}
}
