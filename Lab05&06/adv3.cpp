#include <iostream>

using namespace std;

int main()
{
	int	n, res, i;
	
	cout << "number : ";
	cin >> n;
	
	i = 0;
	res = 0;
	while (++i <= n)
		((i % 2) && (i % 3) ? (res += i) : 0);
	cout << "sum : " << res << endl;
	return (0);
}
