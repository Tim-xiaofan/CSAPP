#include <stdio.h>

typedef unsigned char * byte_pointer;

static void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for(i = 0; i < len; ++i)
	  printf(" %.2x", start[i]);
	printf("\n");
}

static void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}

static void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

static void show_pointer(void * x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}

static void test_show_bytes(int val) 
{
	int i = val;
	float f = (float) i;
	int *pi = &i;
	printf("Original val=%d\n", val);
	printf("show_int:");
	show_int(i);
	printf("show_float:");
	show_float(f);
	printf("show_pointer:");
	show_pointer(pi);
}

int main()
{
	test_show_bytes(12345);
	return 0;
}
