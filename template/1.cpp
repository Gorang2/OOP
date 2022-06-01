#include <iostream>

using namespace std;

template <typename T>
bool less_than(T a, T b)
{
	return a < b;
}

int main()
{
	cout << less_than(2, 3) << endl;
	cout << less_than(2.1, 3.1) << endl;
	cout << less_than("a", "ab") << endl;
}
