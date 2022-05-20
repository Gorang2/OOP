#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;
int main()
{
	ofstream fout("temp.txt");

	srand(time(NULL));
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
			fout << setw(4) << rand() % 100;
		fout << endl;
	}
	fout.close();
}
