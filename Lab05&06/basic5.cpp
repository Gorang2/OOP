#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, m;
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;

	if (n <= 0 || m <= 0)
	{
		cout << "Not a valid size : (" << n << ")x(" << m << ")" << endl;
		return (-1);
	}

	int	i, j;
	i = 0;
	j = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= m)
			cout << setw(4) << i * j;
		cout << endl;
	}
	return 0;
}
