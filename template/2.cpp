#include <iostream>

using namespace std;

template <typename T, int N>

T scale(int val)
{
	return val * N;
}

int main()
{
	int num;
	cin >> num;
	cout << scale<int, 4>(3) << endl;
}
