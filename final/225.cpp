#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int ***arr = new int **[2];
	for (int i=0; i<2; i++)
	{
		arr[i] = new int*[5];
		for (int j=0; j<5; j++)
			arr[i][j] = new int;
	}

	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<5; k++)
			{
				cout << i + j + k << endl;
				arr[i][j][k] = i + j + k;
			}

	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			for (int k=0; k<5; k++)
				cout << arr[i][j][k] << " ";
			cout << endl;
		}
		cout << endl;
	}

	for (int i=0; i<2; i++)
	{
		for (int j=0; j<5; j++)
			delete arr[i][j];
		delete[] arr[i];
	}
	delete[] arr;
}


