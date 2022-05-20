#include <iostream>

using namespace std;

int main()
{
	int	n, i;

	while (true)
	{
		cout << "단 수를 입력하세요: ";
		cin >> n;

		i = 0;
		if (n == -1)
		{
			cout << "종료합니다." << endl;
			return (0);
		}
		else if (0 < n && n < 10)
		{
			while (++i < 10)
				cout << n << " * " << i << " = " << n * i << endl;
			cout << endl;
		}
		else
			cout << "1부터 9까지의 정수를 입력해주세요." << endl << endl;
	}
}	
