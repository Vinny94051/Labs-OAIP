#include <iostream>
#include <time.h>

using namespace std;

struct QueueNode
{
	QueueNode * next;
	int value;
};

void Add(QueueNode **front, QueueNode **back, int value)
{
	QueueNode * temp = new QueueNode;
	temp->value = value;
	temp->next = nullptr;

	if (*front && *back)
	{
		(*back)->next = temp;
		(*back) = temp;
	}
	else
	{
		*front = *back = temp;
	}
}

void Print(QueueNode * node)
{
	if (!node)
		return;

	cout << node->value << " ";

	Print(node->next);
}

void DeleteAll(QueueNode *front)
{
	if (front)
	{
		DeleteAll(front->next);
		delete front;
	}
}

int main()
{
	QueueNode *front = nullptr, *back = nullptr;
	const int queue_size = 20;

	srand(time(0));

	for (int i = 0; i < queue_size; i++)
	{
		Add(&front, &back, rand() % 101 - 50);
	}

	Print(front);
	cout << endl;

	int max = -INT_MAX, min = INT_MAX;
	QueueNode *max_node = nullptr,
			  *min_node = nullptr,
			  *temp = front;

	while (temp)
	{
		int v = temp->value;

		if (v < 0 && v > max)
		{
			max = v;
			max_node = temp;
		}

		if (v > 0 && v < min)
		{
			min = v;
			min_node = temp;
		}

		temp = temp->next;
	}

	
	if (min_node && max_node)
	{
		min_node->value = max;
		max_node->value = min;
	}
	else
	{
		cout << "Error!";
	}

	Print(front);
	DeleteAll(front);
}