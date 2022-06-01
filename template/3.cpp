#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> v(100);
	for (int i=0; i<100; i++)
		v[i] = i;
	auto i = begin(v);
	while (i != end(v))
		cout << *(i++) << endl;
}
