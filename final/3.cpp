#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename T>
class Point : public std::iterator<std::input_iterator_tag, int>
{
	public:
		T x, y;
		Point(T x, T y);
		bool operator==(Point& p);
};

template <typename T>
Point<T>::Point(T x, T y)
{
	this->x = x;
	this->y = y;
}

void get_command(string& command)
{
	command = "";
	do
	{
		cout << endl;
		cout << "1. Print" << endl;
		cout << "2. Find Points" << endl;
		cout << "0. Exit" << endl;
		cout << "input>> ";
		cin >> command;
	}
	while (command != "1" && command != "2" && command !="0");
}

template <typename T, typename Iter>
void count_val(Iter start, Iter end)
{
	T x, y;
	cout << "Enter (x, y): ";
	cin >> x >> y;
	int count = 0;
	for (auto i=start; i != end; i++)
		if (x == (*i).x && y == (*i).y)
			count++;
	cout << "Number of matching elements: " << count << endl;
}


int main() {
       Point<int> myPoints[] = { {1, 2}, {-1, 5}, {3, 7}, {2, 4}, {1, 10}, {1, 2} };
       string command;
 
       while (1) {
              get_command(command);
              if (command == "1")    for_each(begin(myPoints), end(myPoints), [](Point<int> val){ cout << "(" << val.x << ", " << val.y << ")" << endl; });
              else if (command == "2")      count_val<int>(begin(myPoints), end(myPoints));
              else if (command == "0")      break;
       }
       cout << "Exit program.." << endl;
       return 0;
}
