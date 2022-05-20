#include <iostream>
#include <string>
using namespace std;

int main()
{
	string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
	string keyword;

	cout << "키워드 : ";
	cin >> keyword;


	cout << "검색결과 : ";
	string result;
	int start_i = 0, end_i = data.find(",");
	int data_len = data.length();
	if (data.find(keyword) < 0)
		return (0);
	while (start_i < data_len)
	{
		result = data.substr(start_i, end_i - start_i);
		if (result.find(keyword) != string::npos)
			cout << " " << result << " ";
		start_i += result.length() + 1;
		end_i = data.find(",", start_i + 1);
	}
	cout << endl;
}
