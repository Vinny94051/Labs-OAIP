#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;


struct Stack {
	int value, min = 101, minPos;
	Stack *next;
};

int counter = 0;
Stack *Add(Stack *node, int value) {
	counter++;
	Stack *new_node = new Stack;
	new_node->value = value;
	new_node->next = node;

	if (!node || value < node->min)
	{
		new_node->min = value;
		new_node->minPos = counter;
	}
	else {
		new_node->min = node->min;
		new_node->minPos = node->minPos;
	}
	return new_node;
}

int g = 0;
void Print_stack(Stack *node) {
	if (!node) return;

	cout << " Element number : " << g << ":\t" << node->value << endl;
	g++;
	Print_stack(node->next);
}

void DeleteStack(Stack *node) {
	counter = 0;
	if (!node) return;

	DeleteStack(node->next);
	delete node;
}





int main() {

	const int size = 15;
	Stack *node = nullptr;

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		node = Add(node, rand() % 101 - 50);
	}

	Print_stack(node);
	cout << endl;

	cout << "\nThe min = " << node->min <<
		"\nThe number of elements previous minmal = " << size - node->minPos << endl;
	DeleteStack(node);
	system("pause");
	return 0;
}
