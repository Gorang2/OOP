#include <iostream>
#include <vector>

using namespace std;

class Account {
	public : 
		string name;
		int id;
		double balance;
		Account()
		{
		}
		Account(string name, int id, double balance):
			name(name), id(id), balance(balance) {}
		void	withdraw(double money)
		{
			if (balance  >= money)
			       	balance -= money;
			else
			{
				cout << "not enough money." << endl; 
				return;
			}
			cout << "Left : " << balance << endl;
		}
		void print();
};

class Account_new : Account{
	public:
		Account_new(string name, int id, double bal)
		{
			super(name, id, bal);
		}
};

void Account::print()
{
	cout << "name : " << name << endl;
}

void	add_account(vector<Account>& arr)
{
	string name;
	int number;
	double amount;

	cout << "Enter name, Account number, and account balance : ";
	cin >> name >> number >> amount;
	arr.push_back(Account(name, number, amount));
}

void	swap(Account& e1, Account& e2)
{
	Account tmp = e1;
	e1 = e2;
	e2 = tmp;
}

void	sort(vector<Account>& db, bool (*comp)(const Account&, const Account&))
{
	int size = db.size();
	for (int i=0; i<size - 1; i++)
	{
		int min = i;
		for (int j=i + 1; j < size; j++)
			if (comp(db[j], db[min]))
				min = j;
		if (min != i)
			swap(db[i], db[min]);
	}
}

bool	sort_name(const Account& e1, const Account& e2)
{
	return (e1.name < e2.name);
}

int main()
{
	vector <Account>arr;
	Account acc("hyun", 11, 1);;
	Account_new acc2("jiyoung", 12, 2);

	acc.print();
	return 0;
}
