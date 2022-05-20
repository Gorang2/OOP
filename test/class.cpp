#include <iostream>

using namespace std;

class	Book {
	public:
		int id=0;
		char* name;
		Book(int id, const char * _name)
		{
			this->id = id;
			name = new char[strlen(_name)];
			strcpy(name, _name);
		}
		Book(const Book& B)
		{
			id = B.id;
			name = new char[strlen(B.name)];
			strcpy(name, B.name);
		}
		void	get_info()
		{
			cout << this->id << " : " << this->name << endl;
		}

};

int main()
{
	Book book(10, "JY");
	Book book2 = book;

	strcpy(book2.name, "Hyun");
	book.get_info();
	book2.get_info();
}
