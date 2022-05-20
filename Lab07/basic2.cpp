#include <iostream>
#include <string> //string객체 사용
#include <fstream> //ifstream ofstream
#include <iomanip> // setw
using namespace std;
int main() {
	ofstream fout; // processor->file 저장
	/*구현*/ // example.txt 열기
	fout.open("example.txt"); 
	string s2 = "Objective Oriented Programming";
	fout << s2 << endl;
	fout << "Random Variables" << endl;
	fout << "Linear Algebra" << endl;
	fout.close();
	/*구현*/ // fout 닫기
	ifstream fin;
	string s1;
	fin.open("example.txt");
	/*구현*/ // example.txt 열기
	if (!fin) {
		cout << "Error, no such file exists" << endl;
		exit(100);
	}
	 while (getline(fin, s1)) { // line by line으로 example.txt에서 읽어와서 출력
		cout << s1 << endl;
	}
	 /*while (1) { // 띄어쓰기 단위로 example.txt에서 읽어와서 출력
	 	fin >> s1;
		if (!fin)
			break;
		cout << s1 << endl;
	}*/
	fin.close();
}
