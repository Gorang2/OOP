#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("inputt.txt");
	cout << fin.is_open() << endl;
}
