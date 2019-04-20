#include <iostream>
#include <ctime>

using namespace std;

struct Sportman {
	int age;
	char *name = new char[20];
};

void printAge(Sportman *club, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << club[i].age << " ";
	}
	cout << endl;
}

void quickSort(Sportman *array, int low, int high) {
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2].age;
	Sportman temp;

	while (i <= j)
	{
		while (array[i].age < pivot)
			i++;
		while (array[j].age > pivot)
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

void SelectSort(Sportman *array, int n) {
	int counter = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && array[j - 1].age > array[j].age; j--) {
			counter++;
			Sportman temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
		}
	}
	cout << counter << endl;
}


int fullSearch(Sportman *sportman, int size, int age) {
	for (int i = 0; i < size; i++)
	{
		if (age == sportman[i].age) return i;
	}
	cout << "This sportman does not exist." << endl;
	return -1;
}

int binarySearch(Sportman *sportman, int size, int age){
	int middle = size / 2;
	for (int i = 0; i < size && middle < size; i++)
	{
		if (age == sportman[middle].age) return middle;
		else if(age > middle){
			middle = (size+middle)/2;
		}
		else if (age < middle)
		{
			middle /= 2;
		}
	}
	cout << "This sportman does not exist." << endl;
	return -1;
}

int main() {
	srand(time(NULL));

	int SIZE = 10;
	Sportman *club = new Sportman[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		club[i].age = rand() % 10 + 20;
		//club[i].name = name;
		cout << club[i].age << " ";
	}

	cout << endl;
	quickSort(club, 0, SIZE-1);
	printAge(club, SIZE);
	cout << fullSearch(club, SIZE, 28) << endl;
	cout << binarySearch(club, SIZE, 28) << endl;
	
	system("pause");
	return 0;
}
