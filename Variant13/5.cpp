#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double **mat;
	int n, m;
	cin >> n >> m;

	mat = new double*[n];

	for (int i = 0; i < n; i++)
	{
		mat[i] = new double[m];

		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	int min = INT_MAX, max = -INT_MAX;

	for (int i = 0; i < n; i++)
	{
		for (int j = m - i; j < m; j++)
		{
			if (mat[i][j] > max)
			{
				max = mat[i][j];
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (mat[i][j] < min)
			{
				min = mat[i][j];
			}
		}
	}

	cout << "min: " << min << endl;
	cout << "max: " << max;

	for (int i = 0; i < n; i++)
		delete[] mat[i];

	delete[] mat;

	return 0;
}