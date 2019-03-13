#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>
using namespace std;

int main() 
{
	srand(time(NULL));
	string str = {'4',' ','9',' ','3',' ','1',' ','7',' ','5',' ','6',' ','2',' ','8'};
	
for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < str.size()-1; i++)
	{
		if (str.at(i) != ' ') 
		{
			if (char(str.at(i)) > char(str.at(i + 2))) 
			{
				swap(str.at(i), str.at(i + 2));
				i = -1;
			}
		}
	}

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	system("pause");
	return 0;
}