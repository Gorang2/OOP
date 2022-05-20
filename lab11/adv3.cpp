#include <iostream>

using namespace std;

class Account {
	private:
		int id, balance;
		string name;
	public:
		static int sum;
		Account(string name, int id, int balance)
		{
			this->name = name;
			this->id = id; 
			this->balance = balance;
		}
		Account():
			name(""), id(0), balance(0){};
		int getId() const
		{ return id; }
		~Account()
		{ sum += balance; } 
		void setAccount(string name, int id, int balance)
		{
			this->name = name;
			this->id = id;
			this->balance = balance;
		}


};

bool	check(Account *arr, int id, int n)
{
	for (int i=0; i<n; i++)
		if (arr[i].getId() == id)
			return false;
	return true;
}

int Account::sum = 0;
int main()
{
	int n, i;
	cout << "총 학생 수 입력 : ";
	cin >> n;
	Account* arr = new Account[n];
	for (int i=0; i<n; i++)
	{
		int id, balance;
		string name;
		cout << i+1 << "번째 학생 계좌 입력 : 학번 : ";
		cin >> id;
		cout << endl << "이름 : ";
		cin >> name;
		cout << endl << "잔액 : ";
		cin >> balance;
		cout << "=================================" << endl << endl;
		if (check(arr, id, n) == false)
		{
			cout << "중복되거나 잘못된  학번을 입력하셨습니다. 프로그램을 종료합니다." << endl;
			exit(EXIT_FAILURE);
		}
		arr[i].setAccount(name, id, balance);
	}
	delete[] arr;
	cout << "회수된 금액 : " << Account::sum << endl;
	return 0;
}


