#include <iostream>
#include <vector>

using namespace std;

void	rev_vector(vector<int> *v)
{
	int tmp;
	for (int i=0; i<5; i++)
	{
		tmp = (*v)[i];
		(*v)[i] = (*v)[9 - i];
		(*v)[9 - i] = tmp;
	}
}

int main()
{
	vector<int> vec(10);

	for (int i=0; i<10; i++)
		vec[i] = i + 1;
	cout << "기본 Vector 값:" << endl;
	for (int val : vec)
		cout << " " << val;
	cout << endl;
	rev_vector(&vec);
	cout << "함수 실행 후 Vector 값:" << endl;
	for (int val : vec)
		cout << " " << val;
	cout << endl;
}
