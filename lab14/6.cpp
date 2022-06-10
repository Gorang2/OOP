#include <iostream>
#include <vector>

using namespace std;

class IndexException:public exception
{
	string message;
	public:
		IndexException():
			message("Index is out or range. Please try again.") {}
		virtual const char* what() const throw() {
			return message.c_str();
		}
};


int main() {
	vector<int> list{ 10, 20, 30, 40, 50 };
	int num; // 출력할 list의 수
	while (1) {
		cout << "출력할 숫자의 수 : ";
		cin >> num;
		if (num == -1)
		{
			cout << endl;
			break;
		}
		try
		{
			for (int i=0; i<num; i++)
			{
				if (i == list.size())
				{
					cout << endl;
					throw IndexException();
				}
				cout << list[i] << " ";
			}
			cout << endl;
		}
		catch(exception& e)
		{
			cout << "Index is out of range. Please try again." << endl;
		}
	}
	cout << "Program exit..." << endl;
	return 0;
}
