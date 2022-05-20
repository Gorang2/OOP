#include <stdlib.h>
#include <stdio.h>
int main()
{
	int a1 = 1;
	int a2 = 2;
	const int *a = &a1;
	int * const  b = &a2;

	*b = a2;

	printf("%d\n", *b);
	*b = a1;
	printf("%d\n", *b);
}
