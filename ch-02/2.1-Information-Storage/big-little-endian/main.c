/**
 * 检查大小端的基本方法：查看低地址数值
 * */
#include <stdio.h>

static const char *l = "Little Endian";
static const char *b = "Big Endian";

// 方法一: char*
static const char *func1(void)
{
	int i = 1; //最低字节为1
	char *low = (char*)&i;
	if(low[0] == 1) // 最低字节放地址低位
	  return l;
	else
	  return b;
}

// 方法二：union
static const char *func2(void)
{
	union u
	{
		char a;
		int b;
	};
	union u i;
	i.b = 1;
	if(i.a == 1) // 检查低地址的值
	  return l;
	else
	  return b;
}

int main()
{
	printf("Method char*: \t%s\n", func1());
	printf("Method union: \t%s\n", func2());
	return 0;
}
