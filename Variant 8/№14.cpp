#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

struct Quene {
	int value;
	Quene *next;
};

struct Max{
	int value;
	int position;
};

void Create(Quene **begin, Quene **end, int value) {
	Quene *new_quene = new Quene;
	new_quene->value = value;
	new_quene->next = nullptr;

	if (*begin == NULL) {
		*begin = *end = new_quene; //Логиично, что если элемент 1, то он 
									//является и началом и концом очереди
	}
	else {
		(*end)->next = new_quene; //Разыменовав конец очереди,записываем новый в ее конец
		*end = new_quene;
	}
}

Max *SearchMaxPosition(Quene *current) {
	Max *max = new Max;
	max->value = -51;
	max->position = 0;
	int counter = 0;

	while (current->next != NULL) {
		counter++;
		if (current->value > max->value) {
			max->value = current->value;
			max->position = counter;
		}
		current = current->next;
	}
	return max;
}

void Print(Quene *current) {
	if (!current) return;
	cout << current->value << " ";
	Print(current->next);
}


void DeleteAll(Quene *current) {
	if (current) {
		DeleteAll(current->next);
		delete current;
	}
}
int main() {
	srand(time(NULL));

	Quene *begin = NULL, *end = NULL;
	const int size = 9;

	for (int i = 0; i < size; i++)
	{
		int value = rand() % 101 - 50;
		Create(&begin, &end, value);
	}
	Max *max = new Max;
	max = SearchMaxPosition(begin);
	Print(begin);
	cout << endl << "Number of Max elemnet is : " << max->position
		<< endl << "The max element is  : " << max->value << endl;

	Quene *current = new Quene;
	current = begin;
	for (int i = 0; i < size; i++)
	{
		if (i == max->position-2) {
			current->next = current->next->next;
			cout << "Hi" << endl;
			break;
		}
		current = current->next;
	}

	Quene *maxElement = new Quene; //Переставление максимального элемента на первое место
	maxElement->value = max->value;
	maxElement->next = begin;
	begin = maxElement;
	Print(begin);
	
									//Удаление двух препоследних элементов очереди
	current = maxElement;
	while (current->next->next->next!= end) {
		current = current->next;
	}
	current->next = end;
	
	cout << endl;
	Print(begin);
	DeleteAll(begin);

	system("pause");
	return 0;
}
