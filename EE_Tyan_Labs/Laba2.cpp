#include <iostream> 
#include <ctime>

using namespace std;

int generateValue();
int createCi(int a_i, int b_i);
void printArray(int size, int *a);


int main(int argc, char* argv[]) {
	srand(time(NULL));
	const int SIZE = 10;

	int *a = new int[SIZE];
	int *b = new int[SIZE];
	int *c = new int[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		a[i] = generateValue();
		b[i] = generateValue();
		c[i] = createCi(a[i], b[i]);
	}

	printArray(SIZE, a);
	printArray(SIZE, b);
	printArray(SIZE, c);

	system("pause");
	return 0;
}

int generateValue()
{
	return rand()%20+1;
}

int createCi(int a_i, int b_i)
{
	if (a_i > b_i)
		return a_i / b_i;
	else if (a_i < b_i)
		return	b_i / a_i;
	else return 0;
	
}

void printArray(int size, int * a)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
