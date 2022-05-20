#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout("output.txt");
	ifstream fin ("orig.txt");

	int length;
	cout << "length = ";
	cin >> length;

	string str;
	string line;

	while (getline(fin, line))
		str = str + line + " ";
	int i = 0;
	while (str[i])
	{
		fout << str[i];
		if ((i + 1) % length == 0 && i != 0)
			fout << endl;
		i++;
	}
	fout.close();
	fin.close();
}

