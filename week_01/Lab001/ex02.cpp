#include <iostream>

using namespace std;

int main() 
{
/* sizeof 연산자
   : 인자로 준 자료형의 크기를 byte로 반환하는 단항 연산자.
     운영체제별로 자료형의 크기가 상이할 수 있음.
     
*/
	unsigned short siX; // (int) 생략 가능
	unsigned iX;
	long liX;
	long long lliX;
	cout << "sizeof(siX):" << sizeof(siX) << endl;
	cout << "sizeof(iX):" <<  sizeof(iX)  << endl;
	cout << "sizeof(liX):" << sizeof(liX) << endl;
	cout << "sizeof(lliX):" << sizeof(lliX) << endl;
}
