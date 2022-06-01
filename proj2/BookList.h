#ifndef BOOK_H
#include "Book.h"
#endif
class BookList {
	private:
		void slideUp(int location);
		void slideDown(int location);
		Book books[10];
		int count;
		int size;
	public :
		BookList();
		void addBookAt(Book b, int location);
		void addBook(Book b);
		Book findBook(int location) const;
		Book removeBook(int location);
		void displayBooks(std::ostream &out) const;
};

BookList::BookList():count(0){};

void BookList::addBook(Book b)
{
	if (count == 10)
	{
		std::cout << "List is already full." << std::endl;
		return ;
	}
	books[count] = b;
	count++;
}

void BookList::addBookAt(Book b, int location)
{
	if (count == 10)
	{
		std::cout << "List is already full." << std::endl;
		return ;
	}
	if (location <= 0) //when location is smaller than 0, the book should be added in the front of the list
	{
		slideUp(0);
		books[0] = b;
	}
	else if (location > count) //when location is bigger then the current count of books, it should be added in the last of the list
		books[count] = b;
	else if (location > 0 && location < count)
	{
		slideUp(location);
		books[location] = b;
	}
	count++;
}

Book BookList::findBook(int location) const
{
	if (location < 0 || location >= count)
	{
		std::cout << "Invalid Location." << std::endl;
		return (Book());
	}
	return (books[location]);
}

Book BookList::removeBook(int location)
{
	if (location < 0 || location >= count)
	{
		std::cout << "Invalid Location." << std::endl;
		return Book();
	}
	Book tmp = books[location];
	if (count == 1)
		books[0] = Book();
	else
		slideDown(location);
	count--;
	return (tmp);
}

void BookList::slideDown(int location)
{
	for (int i=location; i<count - 1; i++)
		books[i] = books[i + 1];
}

void BookList::slideUp(int location)
{
	for (int i=count; i>location; i--)
		books[i] = books[i - 1];
}

void BookList::displayBooks(std::ostream &out) const
{
	out << "Books in my list:" << endl;
	for (int i=0; i<count; i++)
		books[i].displayBook(out);
}

