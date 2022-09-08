void foo(void)
{
	for(int i = 0; i < 100; ++i)
	{
	}
}

void foo1(void)
{//汇编代码一摸一样
	int i = 0;
	while(i < 100)
	{
		++i;
	}
}
