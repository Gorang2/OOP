#include <iostream>
#include <string>
#include <iomanip>                 
using namespace std;
 
//클래스 구현
class Student
{
	private:
		string name;
		string id;
		string code[100];
		int numCourseTaken;
	public:
		Student(): name(""), id(""), numCourseTaken(0) {}
		Student(string name, string id)
		{
			this->name = name;
			this->id = id;
			this->numCourseTaken = 0;
		}
		void setName(string name)
		{
			this->name = name;
		}
		void setId(string id)
		{
			this->id = id;
		}
		void addCourse(string c)
		{
			code[numCourseTaken++] = c;
		}
		string getId()
		{ return this->id; }
		string getName()
		{ return this->name; }
		string getCode(int i)
		{ return (this->code)[i]; }
		friend ostream& operator<<(ostream& out, Student& s);
		friend class KHUIS;
};

class Course
{
	private:
		string name;
		string code;
	public:
		Course()
		{
			this->name = "";
			this->code = "";
		}
		Course(string name, string code)
		{
			this->name = name;
			this->code = code;
		}
		string getName()
		{ return this->name; }
		string getCode()
		{ return this->code; }
		void setName(string name)
		{
			this->name = name;
		}
		void setCode(string code)
		{
			this->code = code;
		}

		friend class KHUIS;
		friend ostream& operator<<(ostream& out, Course& s);
};
 
class KHUIS
{
	public:
		void printInfo(Student& _stu, Course* _course, int numCourse)
		{
			cout << "[Student and Course Information]" << endl;
			cout << "ID: " << _stu.id << "\tName: " << _stu.name << "\tCourses(taking): ";
			for (int i=0; i<_stu.numCourseTaken; i++)
				cout << _stu.code[i] << " ";
			cout << endl;
			for (int i=0; i<_stu.numCourseTaken; i++)
			{
				cout << "Code :" << _stu.code[i] << "\t";
				for (int j=0; j<numCourse; j++)
					if (_stu.code[i] == _course[j].code)
						cout << "Name :" <<  _course[j].name << endl;
			}
			cout << endl;
		}
};

ostream& operator<<(ostream& out, Student& s)
{
	out << "ID: " << s.id << "\tName: " << s.name << "\tCourses(taking): ";
	for (int i=0; i<100; i++)
		out << s.code[i] << " ";
	return (out);
}
ostream& operator<<(ostream& out, Course& c)
{
	out << "Code :" << c.code << "\tName :" << c.name;
	return (out);
}
	
int main() {
       int numTotalCourse = 3; //총 과목의 개수
       Course *pCourse = new Course[numTotalCourse];
       pCourse[0].setName("객체지향프로그래밍");
       pCourse[0].setCode("CSE100");
       pCourse[1].setName("영상처리");
       pCourse[1].setCode("CSE200");
       pCourse[2].setName("머신러닝");
       pCourse[2].setCode("CSE300");
 
       cout << pCourse[0].getCode() << '\t' << pCourse->getName() << endl; // 그림1. (1)
       cout << setw(50) << setfill('-') << "" << endl;
 
 
       cout << pCourse[0] << endl; // 그림1. (2)
       cout << pCourse[1] << endl;
       cout << pCourse[2] << endl;
       cout << setw(50) << setfill('-') << "" << endl;
 
 
       Student stu1("홍길동", "20181004"), stu2;
       stu1.addCourse("CSE100");
       stu1.addCourse("CSE200");
 
       stu2.setName("김영희");
       stu2.setId("20182000");
       stu2.addCourse("CSE100");
       stu2.addCourse("CSE300");
 
       cout << stu1.getId() << '\t' << stu1.getName() << '\t' << stu1.getCode(0) << endl; // 그림1. (3)
       cout << setw(50) << setfill('-') << "" << endl;
 
       cout << stu1 << endl; // 그림1. (4)
       cout << stu2 << endl;
       cout << setw(50) << setfill('-') << "" << endl;
 
       KHUIS khuis;
       khuis.printInfo(stu1, pCourse, numTotalCourse); // 그림1. (5)
       khuis.printInfo(stu2, pCourse, numTotalCourse);
 
       //pCourse 할당 해제 할 것
       return 0;
}

