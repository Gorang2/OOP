#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FileNotFoundException : public exception {
	string message; // Identifies the exception and filename
	public:
		FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") {}
		virtual const char* what() const throw () {
			return message.c_str();
		}
};
class CStudent
{
	private:
		string m_Name;
		int m_Number;
		string m_Major;
	public:
		CStudent() {}
		~CStudent() {}
		void setAll(string _name, int _num, string _maj) {
		m_Name = _name;
		m_Number = _num;
		m_Major = _maj;
}

	void Display() {
		cout << "이름: " << m_Name << endl;
		cout << "학번: " << m_Number << endl;
		cout << "전공: " << m_Major << endl << endl;
	}
};

vector<CStudent> read_file(string& filename)
{
	vector<CStudent> v;
	fstream f(filename);
	if (!f)
		throw FileNotFoundException(filename);
	int size;
	f >> size;
	string name, major;
	int id;
	for (int i=0; i<size; i++)
	{
		CStudent c;
		f >> name >> id >> major;
		c.setAll(name, id, major);
		v.push_back(c);
	}
	return (v);
}
int main() {
	string str;
	cout << "파일 이름 : ";
	cin >> str;
	try {
		vector<CStudent> numbers = read_file(str);
		for (CStudent value : numbers)
			value.Display();
	}
	catch (std::exception& e) {
		cout << e.what() << '\n';
	}
	return 0;
}
