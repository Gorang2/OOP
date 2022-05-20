#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
//소수 : 1과 자기자신을 제외하고는 약수가 없는 1보다 큰 정수
bool is_prime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
		       return false;	// n을 i로 나눈 나머지가 0이면 false를 리턴
	return true;
}

vector<int> primes(int low, int high) {
	vector<int> result;
	for (int i = low; i <= high; i++)
		if (is_prime(i))
			result.push_back(i); // 소수이면 (is_prime이 참이면) 뒤에 push
	return result;
}

void print(const vector<int>& v) {
	for (auto elem : v)
	cout << setw(4) << elem;
	cout << endl;
}

int main() {
	int low, high;
	cin >> low >> high;
	vector<int> vec = primes(low, high);
	print(vec);
	return 0;
}
