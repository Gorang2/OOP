#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	srand(time(NULL));
	float sum = 0;

	for (int i=0; i<10000; i++)
	{
		double n = (float)(rand()%10000)/10000;
		sum += n*n + sin(n);
	}
	cout << sum/10000 << endl;
}

