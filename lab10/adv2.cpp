#include <iostream>

using namespace std;

class CStudent {
	private :
		long long number;
		string name;
		string major;
	public :
		CStudent():
			number(2018000000), name("홍길동"), major("컴퓨터공학과"){}
		CStudent(long long _num, string _name, string _major):
			number(_num), name(_name), major(_major){}
		void setNumber(long long _num){
			number = _num;
		}
		void setName(string _name)
		{
			name = _name;
		}
		void setMajor(string _major)
		{
			major = _major;
		}
		long long getNumber() { return number; }
		string getName() { return name; }
		string getMajor() { return major;}
		void Display()
		{
			cout << "학번 :" << number << endl;
			cout << "이름 :" << name << endl;
			cout << "전공 :" << major << endl;
			cout << endl;
		}
};

bool	checkNumber(CStudent s[3], int num)
{
	for (int i=0; i<3; i++)
		if (s[i].getNumber() == num)
			return false;
	return true;
}

int main() {
	CStudent s[3]; // 3명의 학생정보를 저장할 class 배열
	int inputNumber; // 키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
	int length = 0; // 현재 입력된 학생의 수
	while (1)
	{
		if (length > 2)
		{
			cout << "----모든입력이 완료되었습니다----" << endl;
			break;
		}
		cout << length + 1 << " 번째 학생 입력" << endl;
		cout << "학번 : ";
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;
		if (checkNumber(s, inputNumber) == false)
		{
			cout << "※ 중복된 학번이 존재합니다" << endl << endl;
			continue;
		}
		s[length] = CStudent(inputNumber, inputName, inputMajor);
		cout << "※입력 완료" << endl << endl;
		length++;
	}
	for (int i=0; i<3; i++)
	{
		cout << i+1 << "학생정보" << endl;
		s[i].Display();
	}
	return 0;
}
