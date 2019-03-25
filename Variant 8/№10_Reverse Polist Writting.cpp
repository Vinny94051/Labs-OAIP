#include <iostream>
#include <string.h>
#include <String>
#include <string>

using namespace std;

int main() {
	string inPut = "a/(b*(c+d))-e";
	cout << "Enter your value " << endl;
	//getline(cin, inPut);			
	cout << inPut << endl;

	string outPutStack = "";
	string outPut = "";
	//Convert into Polish reverse write
	for (int i = 0; i < inPut.size(); i++)
	{
		switch (inPut[i]) {
		case '+': {
			while (outPutStack[0] == '*' || outPutStack[0] == '/' || outPutStack[0] == '+' || outPutStack[0] == '-') {
				outPut.push_back(outPutStack[0]);
				outPutStack.erase(0, 1);
			}
			outPutStack.insert(outPutStack.begin(), '+');
			break;
		}
		case '-': {
			while (outPutStack[0] == '*' || outPutStack[0] == '/' || outPutStack[0] == '+' || outPutStack[0] == '-') {
				outPut.push_back(outPutStack[0]);
				outPutStack.erase(0, 1);
			}
			outPutStack.insert(outPutStack.begin(), '-');
			break;
		}
		case '/':
		{
			while (outPutStack[0] == '*' || outPutStack[0] == '/') {
				outPut.push_back(outPutStack[0]);
				outPutStack.erase(0, 1);
			}
			outPutStack.insert(outPutStack.begin(), '/');
			break;
		}
		case '*': {
			while (outPutStack[0] == '*' || outPutStack[0] == '/') {
				outPut.push_back(outPutStack[0]);
				outPutStack.erase(0, 1);
			}
			outPutStack.insert(outPutStack.begin(), '*');
			break;
		}
		case '(': {
			outPutStack.insert(outPutStack.begin(), '(');
			break;
		}
		case ')':
		{
			outPutStack.insert(outPutStack.begin(), ')');

			int counter = 0;
			while (outPutStack[counter] != '(') {
				if (outPutStack[counter] != ')') {
					outPut.push_back(outPutStack[counter]);
					outPutStack.erase(counter, 1);
					counter--;
				}
				counter++;
			}

			outPutStack.erase(outPutStack.find('('), 1);
			outPutStack.erase(outPutStack.find(')'), 1);
			break;
		}
		case ' ':
		{
			break;
		}
		default:
			outPut += inPut[i];
		}
	}

	for (int i = 0; i < outPutStack.size(); i++)
	{
		outPut.push_back(outPutStack[i]);
	}
	cout << outPut << endl;
	/////////////////////////////////////////////////////////////////////////////////////////// READING
	double a = 8.5, b = 0.3, c = 2.4, d = 7.9, e = 1.6;

	double *array = new double[1];
	int counter = 0;
	for (int i = 0; i < outPut.size(); i++)
	{
		if (outPut[i] != '+' && outPut[i] != '/' && outPut[i] != '*' && outPut[i] != '-') {

			if (outPut[i] == 'a')
				array[counter] = a;
			else if (outPut[i] == 'b')
				array[counter] = b;
			else if (outPut[i] == 'c')
				array[counter] = c;
			else if (outPut[i] == 'd')
				array[counter] = d;
			else if (outPut[i] == 'e')
				array[counter] = e;

			counter++;

		}
		else {
			switch (outPut[i])
			{
			case'+':
				counter--;
				array[counter - 1] = array[counter - 1] + array[counter];
				break;
			case'-':
				counter--;
				array[counter - 1] = array[counter - 1] - array[counter];
				break;
			case'*':
				counter--;
				array[counter - 1] = array[counter - 1] * array[counter];
				break;
			case'/':
				counter--;
				array[counter - 1] = array[counter - 1] / array[counter];
				break;
			default:
				cout << "error";
				break;
			}
		}
	}
	cout << array[0] << endl;
	cout << endl;
	
	system("pause");
	exit(0);
	delete array;
	return 0;
}

