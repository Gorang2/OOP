# include <iostream>
# include <vector>
using namespace std;
bool found_char(const char* s, char ch) {
	/* 구현 */ // s와 ch 만으로 (s,s+1, ...)에 ch가 있는지 true/false return
	while (*s)
	{
		if (*s == ch)
			return (true);
		s++;
	}
	return (false);
}

int main() {
	// 012345(6)
	const char* phrase = "this is a phrase";// ch[]
	 // phrase(\0)==NULL
	for (char ch = 'a'; ch <= 'z'; ch++) { // 'a' == 65, 'z' == 97
		cout << ch << " is ";
		if (!found_char(phrase, ch))
			cout << "NOT";
	cout << " in (" << phrase <<")" << endl;
	}
	return 0;
}
