#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int main() 
{
	// n - строки m - столбцы
	srand(time(NULL));
	int n, m;
	cin >> n >> m;

	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
    }

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 100;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	////////

	int *ptrMin = new int[m];

	int t;
	if (m > n) { t = m; }
	else { t = n; }

	for (int i = 0; i < m; i++)
	{
		int min = 2147483647;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] < min) { min = matrix[j][i]; }
		}
		ptrMin[i] = min;
	}

	for (int i = 0; i < m-1; i++)
	{
		if (ptrMin[i] > ptrMin[i + 1]) 
		{
			swap(ptrMin[i], ptrMin[i+1]);
			
			int *buf = new int[n];
			for (int k = 0; k < n; k++)
			{
				buf[k] = matrix[k][i];
			}
			int *buf_1 = new int[n];
			for (int k_1= 0; k_1 < n; k_1++)
			{
				buf_1[k_1] = matrix[k_1][i+1];
			}
			
			for (int v = 0; v < n; v++)
			{
				matrix[v][i] = buf_1[v];
				matrix[v][i + 1] = buf[v];
			}
			i = -1;
		}
	}

	cout << endl << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}