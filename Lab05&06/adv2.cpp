#include <iostream>

using namespace std;

int main()
{
	int	i, num, res;

	cout << "number : ";
	cin >> num;
	i = 1;
	res = 0;
	while (i <= num)
		res += i++;
	cout << "Sum of 1 to " << num << " = " << res << endl;
	return (0);
}
