#include <iostream>
#include <math.h>
#include <ctime>
#include <string.h>


using namespace std;


int main() {
	srand(time(NULL));
	
	cout << "Enter n & m" << endl;
	int n,m;
	cin >> n >> m;

	int **mat = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = rand() % 10;
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	int *str_sum = new int[n];
	for (int i = 0; i < n; i++)
	{
		str_sum[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			str_sum[i] = str_sum[i] + mat[i][j];
		}
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << str_sum[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str_sum[i] > str_sum[i + 1]) {
				swap(str_sum[i],str_sum[i+1]);
				swap(mat[i], mat[i + 1]);
				i = -1;
			}
			
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
