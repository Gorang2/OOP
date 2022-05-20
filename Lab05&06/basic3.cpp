#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int column = 1, row = 1;
	while (row <= 10) 
	{
		column = 1;
		while (column <= 10) {
			int num;
			num = (row == column ? 1 : 0);
			cout << setw(4) << num;
			column++;
		}
		cout << endl;
		row++;
	}
	return 0;
}
