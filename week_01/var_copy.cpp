#include <iostream>

using namespace std;

//c++에서는 변수에 다른 변수값을 지정하고 기존 값을 수정해도 영향을 받지 않는다.
int main()
{
	int a;
	int b;

	a = 1;
	b = a;
	a = 2;
	cout << b;
}
