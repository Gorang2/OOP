#include <iostream>

using namespace std;

int main()
{
	int	count, num;
	string	flag;
	
	count = 0;
	while (count < 5)
	{
		cout << count + 1 << "번째 정수 : ";
		cin >> num;
		flag = (num % 2 ? "홀수" : "짝수");
		cout << num << "은(는) " << flag << "입니다." << endl;
		count++;
	}
	return (0);
}


