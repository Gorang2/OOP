#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Point
{
	public:
		int x, y;
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		bool operator==(Point p)
		{
			if (this->x == p.x && this->y == p.y)
				return (true);
			return (false);
		}
};

void get_command(string& command)
{
	cout << endl;
	cout << "1. Print" << endl;
	cout << "2. Find Points" << endl;
	cout << "0. Exit" << endl;
	cout << "input>> ";
	cin >> command;
}

template <typename T>
void count_val(T iter, T end)
{
	int x,y;
	cout << "Enter (x, y): ";
	cin >> x >> y;
	int count = 0;
	while (iter != end)
	{
		Point<int> tmp(x, y);
		if ( tmp == *iter)
			count++;
		iter++;
	}
	cout << "Number of matching elements: " << count << endl;
}


int main() {
       Point<int> myPoints[] = { {1, 2}, {-1, 5}, {3, 7}, {2, 4}, {1, 10}, {1, 2} };
       string command;
 
       while (1) {
              get_command(command);
              if (command == "1")    for_each(begin(myPoints), end(myPoints), [](Point<int> p){ cout << "(" << p.x << ", " << p.y << ")" << endl; });
              else if (command == "2")      count_val(begin(myPoints), end(myPoints));
              else if (command == "0")      break;
       }
       cout << "Exit program.." << endl;
       return 0;
}

