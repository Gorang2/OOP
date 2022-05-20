#include <iostream>
#include <cstdlib>

using namespace std;

void	print_arr(int *arr, int n)
{
	cout << "[ Array ]" << endl;
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void	init_arr(int *& arr, int n)
{
	arr = new int[n];
	for (int i=0; i<n; i++)
		arr[i] = rand() % n + 1;
}

bool	dup_in_arr(int *arr, int n)
{
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (arr[i] == arr[j])
				return (true);
	return (false);
}

int main()
{
	int n;
	int *arr;
	srand(time(NULL));
	while (true)
	{
		cout << "Please enter a number: ";
		cin >> n;
		if (n < 2)
		{
			cout << "Wrong number!!!" << endl;
			exit(EXIT_FAILURE);
		}
		n /= 2;
		cout << "Size of random array: " << n << endl;
		init_arr(arr, n);
		print_arr(arr, n);
		(dup_in_arr(arr, n) ? cout << "Duplicates found." << endl : cout << "Duplicates not found." << endl);
		cout << endl;
	}
	return (0);
}
