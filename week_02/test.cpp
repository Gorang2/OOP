#include <stdlib.h>
#include <stdio.h>


char *test(const char **ptr)
{
	printf("inside : %p\n", *ptr);
	*ptr = "Hello World!";
}
int main()

{
	const char *ptr = (char *)malloc(sizeof(char) * 13);
	printf("outside : %p\n", ptr);
	test(&ptr);
	printf("ptr : %s\n", ptr);
}
