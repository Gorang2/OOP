#include <iostream>

using namespace std;

int myadd(int x, int y) 
{
	return (x + y); 
}
int mysub(int x, int y) 
{
	return (x - y); 
}
int mymul(int x, int y) 
{
	return (x * y); 
}
float mydiv(int x, int y) 
{
	return ((float)x / y); 
}

int addmul(int x, int y, int z)
{
	return (mymul(myadd(x, y), z));
}

float muldiv(int x, int y, int z)
{
	return (mydiv(mymul(x, y), (float)z));
}

int addmuladd(int x, int y, int z)
{
	return (mymul(myadd(x, y), myadd(y, z)));
}

float subdivsub(int x, int y, int z)
{
	return (mydiv(mysub(x, y), (float)mysub(y, z)));
}

int	get_num()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	return (n);
}

int main()
{
	int x, y, z;

	x = get_num();
	y = get_num();
	z = get_num();

	cout << "x = " << x << ", " << "y = " << y << ", " << "z = " << z << endl;
	cout << "(x + y) * z = " << addmul(x, y, z) << endl;
	cout << "(x * y) / z = " << muldiv(x, y, z) << endl;
	cout << "(x + y)  * (y + z) = " << addmuladd(x, y, z) << endl;
	cout << "(x - y) / (y - z) = " << subdivsub(x, y, z) << endl;
	return (0);
}
