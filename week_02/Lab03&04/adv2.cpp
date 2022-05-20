#include <iostream>

using namespace std;

void print_DOB(int year=1900, int month=1, int day=1)
{
	cout << "생년월일은 " << year << "년 " << month << "월 " << day << "일입니." << endl;
}

int main()
{
	int y, m, d;
	print_DOB();
	cout << "year 입력 : ";
	cin >> y;
	cout << "month 입력 : ";
	cin >> m;
	cout << "day 입력 : ";
	cin >> d;
	print_DOB(y, m, d);
	return (0);
}

