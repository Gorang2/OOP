#include <iostream>

#include <fstream>

#include <string>

using namespace std;

 
void get_num(int& num);
void get_filename(string& filename);
void open_file(ifstream& fin, string filename);
void countSameNum(ifstream& fin, int num, int &count);

void get_num(int& num)
{
	cout << "Enter a number : ";
	cin >> num;
}

void get_filename(string& filename)
{
	cout << "Enter a file name : ";
	cin >> filename;
}

void open_file(ifstream& fin, string filename)
{
	fin.open(filename);
	if (!fin)
	{
		cout << "Error : file open failed" << endl;
		exit(EXIT_FAILURE);
	}
}	

char *itoa(int n)
{
	int count=0;
	int n_cop = n;
	while (n_cop)
	{
		n_cop/=10;
		count++;
	}
	
	char *s = new char[count + 1];
	int i = count - 1;
	while (n/10)
	{
		s[i--] = n%10 + '0';
		n /= 10;
	}
	s[i] = n + '0';
	s[count] = 0;
	return s;
}

void countSameNum(ifstream& fin, int num, int& count)
{
	string s;
	count = 0;
	char * n = itoa(num);
	while (fin)
	{
		fin >> s;
		if (s == n)
			count++;
	}
	delete[] n;
}

 

 

int main() {

       int num, count;

       string filename;

       ifstream fin;

       ofstream fout;

 

       get_filename(filename);

       get_num(num);

       open_file(fin,filename);

       countSameNum(fin, num, count);

 

       cout << "Output: " << count << endl;

 

       fin.close();

       return 0;

}









