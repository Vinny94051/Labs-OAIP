#include <iostream> 
#include <ctime>
#include <string.h>


using namespace std;

void printString(string str);

class Book {
private:
	string name;
public:
	Book(string name) {
		this->name = name;
	}

	Book() {}

	string getBook() {
		return name;
	}
};

class Section {
private:
	int size = 10;
	Book *books = new Book[size];
	string name;
public:

	Section(string name, Book *books) {
		this->name = name;
		this->books = books;
	}

	Section() {}

	int getSize() {
		return size;
	}

	Book getBook(string name) {
		for (int i = 0; i < size; i++)
		{
			if (name == books[i].getBook())
				return books[i];
		}

		return Book("NULL");
	}

	void addBook(Book book) {
		size++;
		books[size - 1] = book;
	}

	string getSectionName() {
		return this->name;
	}

	void printSection() {
		for (int i = 0; i < size; i++)
		{
			printString(books[i].getBook());

		}
	}
};


class Library
{
private:
	int size = 5;
	Section *sections = new Section[size];
public:

	Library() {}

	int getSize() {
		return size;
	}

	Library(Section *sections) {
		this->sections = sections;
	}

	Section getSection(int number) {
		return sections[number - 1];
	}

	void addSection(Section section) {
		size++;
		sections[size - 1] = section;
	}
};



class Subscription {
private:
	int size = 0;
	Book *userBooks = new Book[size];
public:
	Subscription() {}

	void addBookIntoSubscription(Book book) {
		size++;
			Book *userBook = new Book[size+1];
			for (int l = 0; l < size-1; l++)
			{
				userBook[l] = userBooks[l];
			}
			userBook[size - 1] = book;
			userBooks = userBook;
		
	}

	Book addBookByLib(string name, Library lib) {
		for (int i = 0; i < lib.getSize(); i++)
		{
			Section section = lib.getSection(i + 1);
			for (int  k = 0; k < section.getSize(); k++)
			{
				Book booktmp = section.getBook(name);

				if (booktmp.getBook() != "NULL") {
					addBookIntoSubscription(booktmp);
					return booktmp;
				}
			}
		}
		return Book("NULL");
	}

	void deleteBook(string name) {
		for (int i = 0; i < size; i++)
		{
			if (name == userBooks[i].getBook())
			{
				userBooks[i] = Book(" ");
				return;
			}
		}
	}

	void showUserList() {
		for (int i = 0; i < size; i++)
		{
			printString(userBooks[i].getBook());
		}
	}
};


int main() {
	
	Library library;
	int sectionsNumber = 5;
	Section *sections = new Section[sectionsNumber];
	int booksNumber = 10;
	Book *books = new Book[booksNumber];

	string sectionName = "section name";
	string bookName = "bookName";

	for (int i = 0; i < sectionsNumber; i++)
	{
		books = new Book[booksNumber];
		for (int k = 0; k < booksNumber; k++)
		{
			books[i] = Book(bookName + (char)k );
		}

		 sections[i] =  Section(sectionName,books);
	}

	library = Library(sections);

	Subscription user;

	user.addBookIntoSubscription(Book("12"));
	user.addBookIntoSubscription(Book("21"));
	user.addBookIntoSubscription(Book("211"));
	user.showUserList();
	user.deleteBook("211");
	user.showUserList();

	system("pause");
	return 0;
}

void printString(string str)
{
	for (int k = 0; k < str.size(); k++)
	{
		cout << str[k];
	}
	cout << endl;
}
