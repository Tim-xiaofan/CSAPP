#include <stdio.h>

int fun1(int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8)
{
	int c = 10;
	return x1 + x2 + x3 + x4 + x5 + x6+ x7 + x8 + c;
}

int main()
{
	fun1(1, 2, 3, 4, 5, 6, 7, 8);
	return 0;
}
