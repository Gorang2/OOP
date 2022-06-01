#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;
class Book {
	private :
		std::string title;
		std::string author;
		std::string genre;
		int year;

	public:
		Book();
		void setTitle(std::string newTitle);
		void setAuthor(std::string newAuthor);
		void setYear(int newYear);
		void setGenre(std::string newGenre);
		std::string getTitle() const;
		std::string getAuthor() const;
		int	getYear() const;
		std::string getGenre() const;
		void	displayBook(std::ostream &out) const;
};

Book::Book()
{
	title = "";
	author = "";
	genre = "";
	year = 2016;
}

void Book::displayBook(std::ostream &out) const
{
	out << "Title: " << getTitle() << endl;
	out << "Author: " << getAuthor() << endl;
	out << "Year: " << getYear() << endl;
	out << "Genre: " << getGenre() << endl;
}

std::string Book::getAuthor() const
{ return (author); }

std::string Book::getGenre() const
{ return (genre); }

std::string Book::getTitle() const
{ return (title); }

int Book::getYear() const
{ return (year); }

void Book::setAuthor(std::string newAuthor)
{ author = newAuthor; }

void Book::setGenre(std::string newGenre)
{ genre = newGenre; }

void Book::setTitle(std::string newTitle)
{ title = newTitle; }

void Book::setYear(int newYear)
{ year = newYear; }

#endif
