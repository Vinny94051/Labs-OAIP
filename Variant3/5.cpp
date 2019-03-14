#include <limits.h> 
#include <iostream> 

using namespace std;

int main()
{ //create array 
	int rows;
	int cols;
	cout << "Input rows & cols: ";
	cin >> rows >> cols;
	int **arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	//filling array 
	cout << endl;
	cout << "fill the array: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]: ";
			cin >> arr[i][j];
			cout << endl;
		}
	}
	//show the array 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	//code 
	int *bool_arr = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		int k = 0;
		int s = cols - 1;
		while (k < cols / 2)
		{
			if (arr[i][k] == arr[i][s])
			{
				bool_arr[i] = 1;
			}
			else { bool_arr[i] = 0; }
			k++;
			s--;
		}
	}
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << bool_arr[i] << " ";
	}

	delete[] bool_arr;

	//delete array 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}