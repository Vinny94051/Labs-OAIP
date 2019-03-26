#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct TreeSet {
	int value;
	TreeSet *left;
	TreeSet *right;
}*root;


TreeSet *Add(TreeSet **root, int value) {
	if ((*root) == NULL) {								//If root is empty
		(*root) = new TreeSet;
		(*root)->value = value;
		(*root)->left = (*root)->right = NULL;
		return *root;
	}

	if (value > (*root)->value) {						//Sort part
		return Add(&(*root)->right, value);
	}
	else {
		return Add(&(*root)->left, value);
	}
}

void GoToXY(short x, short y)
{
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(StdOut, coord);
}

void print(TreeSet *root, short x, short y, short a, char c) { //This fuction work uncorrectly. Print less element than tree has.
	if (root)
	{
		if (a>0 && c != 'k')
		{
			if (c == 'l')
				x -= 10;
			else
				x += 10;
		}
		else
			if (c != 'k')
				if (c == 'l')
					x -= 4;
				else
					x += 4;

		GoToXY(x, y += 2);

		a--;

		printf("%5d", root->value);
		print(root->left, x, y, a, 'l');
		print(root->right, x, y, a, 'r');
	}
}


int numberOfleaf(TreeSet *root, int k, int *counter) {
	if (!root) return 1;
	counter[k]++;
	k++;
	return numberOfleaf(root->left, k, counter) + numberOfleaf(root->right, k, counter);
}

int main() {
	srand(time(NULL));

	const int SIZE = 12; //recomend size for perfect work
	
	for (int i = 0; i < SIZE; i++)
	{
		Add(&root, rand() % 5000);
	}

	print(root, 37, 2, 2, 'k'); printf("\n"); // print tree
	cout << "\n\n\n\n\n\n\n\n\n";

	int *counter = new int[10];

	for (int i = 0; i < 10; i++)
	{
		counter[i] = 0;
	}

	numberOfleaf(root, 0, counter);
	int i = 0;
	while (counter[i] != 0) {
		cout << counter[i] << " ";
		i++;
	}
	cout << endl;
	system("pause");
	return 0;
}
