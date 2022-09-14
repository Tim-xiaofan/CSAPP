#include <stdio.h>

int main()
{
	int lval = 0xFEDCBA98 << 32; 
	printf("0xFEDCBA98 << 32:%d\n", lval);
	int aval = 0xFEDCBA98 >> 36; 
	printf("0xFEDCBA98 >> 36:%d\n", aval);
	unsigned uval = 0xFEDCBA98u >> 40;
	printf("0xFEDCBA98u >> 40:%u\n", uval);
	return 0;
}
