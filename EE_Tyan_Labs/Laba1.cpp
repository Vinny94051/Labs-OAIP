#include <iostream>
#include <string.h>
#include <String>

using namespace std;

class String {
private:
	string str;
	int size;
public:
	String(string str) {
		this->str = str;
		this->size = str.size();
	}

	//Увеличивает размер строки на 1 символ, добавляя нижнее подчеркивание в конец
	String operator++(int number) {
		this->size = size++;
		this->str = str + '_';
		return *this;
	}

	//Увеличивает размер строки на 1 символ, добавляя нижнее подчеркивание в начало
	String operator++() {
		this->size = ++size;
		this->str = '_' + str;
		return *this;
	}

	int getSize() {
		return this->size;
	}

	void print() {
		cout << this->str << endl;
	}
};

int main() {
	String str("Hello world");
	str.print();
	cout << str.getSize() << endl;
	str++;
	str.print();
	cout << str.getSize() << endl;
	++str;
	str.print();
	cout << str.getSize() << endl;

	system("pause");
	return 0;
}
