#include <iostream>
#include <iomanip>
using namespace std;

void display(int**&map, int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			cout << setw(4) << map[i][j] << " ";
		cout << endl;
	}
}
int** generator(int n)
{
	int **map = new int*[n];
	for (int i=0; i<n; i++)
		map[i] = new int[n];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			map[i][j] = 0;

	int i = 0;
	int j = n/2;
	int count = 0;
	while (count < n*n)
	{
		map[i][j] = ++count;
		if (((i - 1 >= 0 && j + 1 < n) &&  map[i - 1][j + 1] != 0) || (i==0 && j == n - 1))
		       i++;
		else	
		{
			i--;
			j++;
		}
		if (i<0)
			i = n - 1;
		else if (j == n)
			j = 0;
	}
	return (map);
}

int main()
{
	int n;
	cout << "홀수 숫자를 하나 입력해 주세요 : ";
	cin >> n;
	int **map= generator(n);
	display(map, n);
}





