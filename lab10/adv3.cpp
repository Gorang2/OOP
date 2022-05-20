#include <iostream>
#include <vector>

using namespace std;

class Student {
	private :
		string name;
		int id;
		string dpt;
		vector<string>classes;
		vector<char>grades;
	
	public :
		Student() : name("defalut"), id(0), dpt("depart"){};
		Student(string _name, int _id, string _dpt):
			name(_name), id(_id), dpt(_dpt) {};
		void setName(string _name){ name = _name; }
		void setID(int _id){ id = _id; }
		void setDpt(string _dpt){ dpt = _dpt; }
		void print(){ cout << name << " " << id << " " << dpt << endl; }
		void addGrade(string _class, char grade)
		{
			classes.push_back(_class);
			grades.push_back(grade);
		}
		float getGPA()
		{
			int sum = 0;
			int count = 0;
			for (char elem : grades)
			{
				'A' + ('F' - elem) <= 'F' ? sum += ('F' - elem) - 1 : sum += 'F' - elem;
				count++;
			}
			return (sum / (float)count);
		}
		void printGrades()
		{
			int size = classes.size();
			for (int i=0; i<size; i++)
				cout << classes[i] << " " << grades[i] << endl;
			cout << "GPA : " << getGPA() << endl;
		}
		void getYear(int year)
		{
			int years = year - (id/1000000) + 1;
			if (years < 1)
			{
				cout << "Invalid year input. Year should be at least " << id / 1000000 <<  endl;
				return ;
			}
			switch (years)
			{
				case 1:
					cout << "Freshmen(1학년)" << endl;
					break;
				case 2:
					cout << "Sophomore(2학년)" << endl;
					break;
				case 3:
					cout << "Junior(3학년)" << endl;
					break;
				case 4:
					cout << "Senior(4학년)" << endl;
					break;
				default :
					cout << "About to graduate(5학년)" << endl;
					break;
			}
		}
};

int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";
	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";
	return 0;
}



