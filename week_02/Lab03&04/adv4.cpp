#include <iostream>

using namespace std;

void	swap_call_by_value(int x, int y)
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}

void	swap_call_by_reference(int& x, int& y)
{
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}

void get_data(int& x, int& y)
{
	cout << "x 입력: ";
	cin >> x;

	cout << "y 입력: ";
	cin >> y;
	cout << endl;
}
int main()
{
	int x, y;

	get_data(x, y);
	cout << "swap_call_by_value 함수 사용 전" << endl << "x = " << x << ", y = " << y << endl;
	swap_call_by_value(x, y);
	cout << "swap_call_by_value 함수 사용 후" << endl << "x = " << x << ", y = " << y << endl;
	
	cout << endl;

	cout << "swap_call_by_reference 함수 사용 전" << endl << "x = " << x << ", y = " << y << endl;
	swap_call_by_reference(x, y);
	cout << "swap_call_by_reference 함수 사용 후" << endl << "x = " << x << ", y = " << y << endl;
	return (0);
}
