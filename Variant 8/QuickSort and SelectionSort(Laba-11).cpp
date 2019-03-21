#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

struct Industry {
	int workStart;
	int numberofIndustry;
};


void quickSort(Industry *array, int low, int high) {
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2].numberofIndustry;
	Industry temp;

	while (i <= j)
	{
		while (array[i].numberofIndustry < pivot)
			i++;
		while (array[j].numberofIndustry > pivot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort(array, low, j);
	if (i < high)
		quickSort(array, i, high);
}

void SelectSort(Industry *array, int n) {
	int counter = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && array[j - 1].numberofIndustry > array[j].numberofIndustry; j--) {
			counter++;
			Industry temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
		}
	}
	cout << counter << endl;
}

void printIndustry(Industry *array, int size) {
	for (int i = 0; i < size; i++)
	{
		cout <<"Number : "<< array[i].numberofIndustry << " " << "\tWork start : " << array[i].workStart << endl;
	}
}

int main() {
	srand(time(NULL));
	//Create Industry
	const int SIZE = 12;
	Industry *ind = new Industry[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		ind[i].numberofIndustry = rand() % 101 - 50;
		ind[i].workStart = rand() % 101 - 50;

	}

	printIndustry(ind, SIZE);
	//Sort
	quickSort(ind, 0, SIZE);
	SelectSort(ind, SIZE);
	
	cout << endl;
	printIndustry(ind, SIZE);



	system("pause");
	return 0;
}
