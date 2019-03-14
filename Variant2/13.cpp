#include <time.h>
#include <iostream>

using namespace std;

struct StackNode
{
	int value;
	StackNode* next;
};

StackNode* Add(StackNode* node, int value)
{
	StackNode* new_node = new StackNode;
	new_node->value = value;
	new_node->next = node;

	return new_node;
}

void Print(StackNode* node)
{
	if (!node)
		return;

	cout << node->value << " ";

	Print(node->next);
}

void DeleteAll(StackNode* node)
{
	if (!node)
		return;

	DeleteAll(node->next);
	delete node;
}

int main()
{
	int stack_size;
	StackNode* top = NULL;

	cout << "Number of elements: " << endl;
	cin >> stack_size;

	for (int i = 0; i < stack_size; i++)
	{
		int temp;
		cin >> temp;
		top = Add(top, temp);
	}

	cout << "Stack: ";

	Print(top);

	cout << endl;

	StackNode * second = NULL, * current = top;

	while (current)
	{
		if (current->value % 2 == 0)
		{
			second = Add(second, current->value);
		}

		current = current->next;
	}

	cout << endl << "Second stack:" << endl;
	Print(second);


	DeleteAll(top);
	DeleteAll(second);

	return 0;
}