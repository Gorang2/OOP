#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

class FileNotFoundException : public exception {
	string message;
	public:
		FileNotFoundException(string _m) :
			message("File \""+ _m + "\" not found") {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
};

int main()
{
	ofstream ofs;
	ofs.open("temp.txt");
	vector< vector<int> > v(10);
	srand(time(NULL));
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			v[i].push_back(rand() % 101);

	// 임의의 10x10 행렬 저장 구현
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
			ofs << v[i][j] << " ";
		ofs << endl;
	}
	ofs.close();

	// 파일이름 입력
	string filename;
	cout << "파일 이름 : ";
	cin >> filename;
	ifstream fin;

	vector < vector<int> > v2;
	try
	{
		fin.open(filename);
		if (!fin)
			throw(FileNotFoundException(filename));
	}
	catch(exception &e)
	{
		cout << endl;
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	for (int i=0; i<10; i++)	
	{
		vector <int> tmp(10);
		for (int j=0; j<10; j++)
			fin >> tmp[j];
		v2.push_back(tmp);
	}
	int row, col;
	cout << "출력할 행 크기 : ";
	cin >> row;
	cout << "출력할 열 크기 : ";
	cin >> col;
	try
	{
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
				cout << v2.at(i).at(j) << " ";
			cout << endl;
		}
	}
	catch(exception& e)
	{
		cout << endl << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	// 입력받은 파일이름에 맞는 파일을 읽어와 vector로 입력 후, 출력 구현

	return 0;
}

