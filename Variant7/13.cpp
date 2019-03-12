#include <time.h>
#include <iostream>

using namespace std;

struct StackNode
{
	int value, max, dst;
	StackNode * next;
};

StackNode * Add(StackNode * node, int value)
{
	StackNode * new_node = new StackNode;
	new_node->value = value;
	new_node->next = node;

	if (!node || value >= node->max)
	{
		new_node->max = value;
		new_node->dst = 0;
	}
	else
	{
		new_node->max = node->max;
		new_node->dst = node->dst + 1;
	}

	return new_node;
}

void Print(StackNode * node)
{
	if (!node)
		return;

	cout << node->value << " ";

	Print(node->next);
}

void DeleteAll(StackNode * node)
{
	if (!node)
		return;

	DeleteAll(node->next);
	delete node;
}

int main()
{
	const int stack_size = 20;
	StackNode * top = nullptr;

	srand(time(0));

	for (int i = 0; i < stack_size; i++)
	{
		top = Add(top, rand() % 101 - 50);
	}

	cout << "Stack: ";

	Print(top);

	cout << endl;

	cout << "Max element: " << top->max << endl;
	cout << "Distance: " << top->dst << endl;

	DeleteAll(top);

	return 0;
}