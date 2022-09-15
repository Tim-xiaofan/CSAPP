#include <stdio.h>

void inplace_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

int main(int argc, char *argv[])
{
	int a = 0, b = 1;
	inplace_swap(&a, &b);
	printf("After swap: a=%d, b=%d\n", a, b);
	return 0;
}
