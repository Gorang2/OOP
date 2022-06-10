#include <iostream>

using namespace std;

int main()
{
	while (1)
	{
		string s;
		cout << "문자열 하나를 입력해주세요 : ";
		cin >> s;
		if (s == "q" || s == "Q")
			break;
		auto f = [s](void){
			int len = s.length() - 1;
			bool flag = true;
			cout << "입력하신 문자열의 역순 : ";
			int i = 0;
			while (len != -1)
			{
				cout << s[len];
				if (s[len] != s[i])
					flag = false;
				i++;
				len--;
			}
			cout << endl;
			if (flag)
				cout << "이 문자는 회문입니다." << endl;
			else
				cout << "이 문자는 회문이 아닙니다." << endl;
			cout << endl;
		};
		f();
	}
	cout << "프로그램을 종료합니다." << endl;
}
