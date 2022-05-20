#include <iostream>
#include <vector>

using namespace std;

class	Point {
	public :
		double x;
		double y;
};

int main()
{
	Point pt1 = Point();
	Point pt2 = Point();

	pt1.x = 1;
	pt1.y = 2;
	pt2 = pt1;

	cout << pt1.x << pt1.y << endl;
	cout << pt2.x << pt2.y << endl;
	cout << "Change pt1" << endl;
	pt1.x = 3;
	pt1.y = 4;

	cout << pt2.x << pt2.y << endl;
	return 0;
}
