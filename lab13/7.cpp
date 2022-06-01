#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
	srand(time(NULL));

	vector<int> vector1(10);
	vector<int> vector2(10);

	auto iter1 = begin(vector1);
	auto iter2 = begin(vector2);

	cout << "<vector 1>" << endl;
	for (auto iter=iter1; iter<end(vector1); iter++)
	{
		*iter = rand() % 11;
		cout << *iter << " ";
	}
	cout << endl;
	cout << "<vector 2>" << endl;
	for (auto iter=iter2; iter<end(vector2); iter++)
	{
		*iter = rand() % 21;
		cout << *iter << " ";
	}
	cout << endl;
	int min = 200;
	int max = 0;
	for (auto i1=iter1; i1<end(vector1); i1++)
		for (auto i2=iter2; i2<end(vector2); i2++)
		{
			if ((*i1) * (*i2) < min)
				min = (*i1) * (*i2);
			if ((*i1) * (*i2) > max)
				max = (*i1) * (*i2);
		}
	cout << "최댓값 = " << max << endl;
	cout << "최솟값 = " << min << endl;
}

