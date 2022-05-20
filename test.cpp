#include <iostream>

using namespace std;

class Base {
	private:
		int year;
	protected:
		int age;
	public:
		int h;
};
class Derived:public Base
{
};

int main()
{
	Derived d = Base();
	cout << d.age << endl;
}
