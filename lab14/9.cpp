#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

class NoFileException:public exception
{
	string message;
	public:
		NoFileException(string mes):
			message("File \"" + mes +"\" not found") {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
};


int main()
{
	ofstream ofs;
	ofs.open("temp.txt");

	srand(time(NULL));
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
			ofs << setw(3) << rand()%101 << " ";
		ofs << endl;
	}
	// 임의의 10x10 행렬 저장 구현
	ofs.close();
	// 파일이름 입력
	string fname;
	cout << "파일 이름 : ";
	cin >> fname;

	try
	{
		ifstream fin(fname);
		if (!fin)
			throw (NoFileException(fname));
		vector< vector<int>> v(10);
		for (int i=0; i<10; i++)
			for (int j=0; j<10; j++)
			{
				int val;
				fin >> val;
				v[i].push_back(val);
			}

		for (int i=0; i<10; i++)
		{
			for (int j=0; j<10; j++)
				cout << setw(3) <<  v[i][j] << " ";
			cout << endl;
		}
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}


	// 입력받은 파일이름에 맞는 파일을 읽어와 vector로 입력 후, 출력 구현
	return 0;
}
