#include <iostream>
#include <ctime>

using namespace std;

struct QueneTwo {
	int value;
	QueneTwo *next;
	QueneTwo *prev;
};

void NewQueneTwo(QueneTwo **head, QueneTwo **newElement) {
	*head = new QueneTwo;
	*newElement = new QueneTwo;
	(*head)->next = NULL;
	(*head)->prev = *newElement;
	(*head)->value = rand() % 101 - 50;

	(*newElement)->next = *head;
	(*newElement)->prev = NULL;
	(*newElement)->value = rand() % 101 - 50;
}

QueneTwo *AddNewEnd(int value, QueneTwo *end) { //Add new element int after last (end).
	QueneTwo *newEnd = new QueneTwo;
	newEnd->value = value;

	end->next = newEnd;
	newEnd->prev = end;
	newEnd->next = NULL;
	return newEnd;
}

QueneTwo *AddNewHead(int value, QueneTwo *head) { //Add new element before the first (head).
	QueneTwo *newHead = new QueneTwo;
	newHead->value = value;

	newHead->next = head;
	head->prev = newHead;
	newHead->prev = NULL;

	return newHead;
}

void PrintFromHead(QueneTwo *head) {
	if (!head) return;
	QueneTwo *cuncurrent = new QueneTwo;
	cuncurrent = head;
	while (cuncurrent != NULL) {
		cout << cuncurrent->value << " ";
		cuncurrent = cuncurrent->next;
	}
}

void PrintFromEnd(QueneTwo *end) {
	if (!end) return;
	QueneTwo *cuncurrent = new QueneTwo;
	cuncurrent = end;
	while (cuncurrent != NULL) {
		cout << cuncurrent->value << " ";
		cuncurrent = cuncurrent->prev;
	}
}

void queneSort(QueneTwo *head, int size) {
	QueneTwo *current = new QueneTwo;
	QueneTwo *prev = new QueneTwo;
	current = head;
	bool sortFlag = false;

	for (int i = 0; i < size; i++)
	{
		if (current->value > current->next->value) {
			swap(current->value, current->next->value);
			current = head;
			i = -1;
		}
		else if (current->value < current->prev->value)
		{
			swap(current->value, current->prev->value);
		}
		prev = current;
		current = current->next;
		current->prev = prev;
	}
}


int queneSearch(QueneTwo *end, int searcheableValue, int size) {
	QueneTwo *current = new QueneTwo;
	current = end;
	int counter = size;

	while (current->prev != NULL)
	{
		if (current->value == searcheableValue) {
			cout << "\nWe have this number.\nIts number is : " << counter << endl;
			return current->value;
		}
		current = current->prev;
		counter--;
	}
	cout << "We have no this number :( " << endl;
}

void cycleMove(QueneTwo *head, int size, QueneTwo *end) {
	int *quene = new int[size+2];
	QueneTwo *t = head;
	quene[0] = end->value;
	int counter = 1;
	while (t) {
		quene[counter] = t->value;
		t = t->next;
		counter++;
	}
	t = head;
	for (int i = 0; i < size+2; i++)
	{
		t->value = quene[i];
			t = t->next;
	}
	}

void deleteQuene(QueneTwo *head) {
	QueneTwo *current = new QueneTwo;

	QueneTwo *t = new QueneTwo;
	current = head;
	while (current->next != NULL) {
		t = current;
		current = current->next;
		current->prev = t;
		delete current->prev;
	}
}
int main() {
	srand(time(NULL));
	QueneTwo *head, *newElemnt, *end;
	NewQueneTwo(&end, &head);

	const int  SIZE = 5;

	for (int i = 0; i < SIZE; i++)
	{
		head = AddNewHead(rand() % 101 - 50, head);
	}


	PrintFromHead(head);
	queneSort(head, SIZE);
	cout << endl;
	PrintFromHead(head);
	cout << endl;

	const int myVariantNumber = 5;
	queneSearch(end, myVariantNumber, SIZE);
	cycleMove(head, SIZE, end);
	cout << "\n";
	PrintFromHead(head);
	cout << endl;

	deleteQuene(head);
	system("pause");
	return 0;
}
