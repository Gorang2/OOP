#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("test1.txt");
	fout.open("output.txt");
	string line;
	while (getline(fin, line))
	{
		fout << line;
		fout << endl;
	}
	fin.close();
	fout << endl;
	fin.open("test2.txt");
	while (getline(fin, line))
	{
		fout << line;
		fout << endl;
	}
	fin.close();
	fout.close();
}
