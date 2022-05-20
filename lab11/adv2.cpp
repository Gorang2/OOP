#include <iostream>

using namespace std;

class Account {
	private :
		string name;
		string id;
		int balance;

	public :
		Account():
			name(""), id(""), balance(0){};
		Account(string name, string id, int balance)
		{
			this->name = name;
			this->id = id;
			this->balance = balance;
		}
		string getId() const
		{ return (this->id); }
		string getName() const
		{ return (this->name); }
		int getBalance() const
		{ return (this->balance); }
	
		void display() const
		{
			cout << "학번 : " << this->id << ", 이름 : " << this->name << ", 잔액 : " << this->balance << endl;
		}
		Account& operator-(int balance)
		{
			this->balance = 0;
			return (*this);
		}
		Account& operator+(Account& ac)
		{
			this->balance += ac.balance;
			return (*this);
		}
};

ostream& operator<<(ostream &cout, Account &ac)
{
		return (cout << "학번: " << ac.getId() << ", 이름: " << ac.getName() << ", 잔액: " << ac.getBalance() << endl);
}

void	finish(Account arr[3])
{
	cout << "종료합니다." << endl;
	for (int i=0; i<3; i++)
	{
		arr[i].display();
	}
}

int  getIndex(Account arr[3], string id)
{
	for (int i=0; i<3; i++)
		if (arr[i].getId() == id)
			return i;
	return 0;
}

int main() {
	Account acnt[3] = {
	Account("장윤호", "2014", 10000),
	Account("김유민", "2019", 0),
	Account("박진배", "2013", 5000),
	};
	string sending_id, getting_id;
	while (true)
	{
		bool flag = 0;
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> sending_id;
		if (sending_id == "종료")
		{
			finish(acnt);
			return 0;
		}
		cout << "돈을 받을 학생의 학번을 입력하세요 : ";
		cin >> getting_id;
		Account *sender = acnt + getIndex(acnt, sending_id);
		Account *getter = acnt + getIndex(acnt, getting_id);
		if (sender->getId() == getter->getId())
		{
			cout << "보내는 학생 또는 받는 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
			continue;
		}
		if (sender->getBalance() == 0)
		{
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue;
		}
		(*getter) = (*getter) + (*sender);
		(*sender) = (*sender) - sender->getBalance();
		cout << "보낸 학생의 잔액 => " << (*sender);
		cout << "받은 학생의 잔액 => " << (*getter);
	}
}


		
