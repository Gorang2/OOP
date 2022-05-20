#include <iostream>

using namespace std;


int get_gcd(int x, int y)
{
	if (x % y == 0)
		return (y);
	else if (y == 0)
		return (x);
	return (get_gcd(y, x % y));
}

int main()
{
	int x, y, res;

	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	x = abs(x);
	y = abs(y);
	res = get_gcd(max(x, y), min(x, y));
	cout << "gcd(" << x << "," << y << ") = " << res << endl;
}
