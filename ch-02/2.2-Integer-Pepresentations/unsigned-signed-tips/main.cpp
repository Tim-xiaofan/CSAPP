#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using std::cout;
using std::endl;
using std::string;

float sum_elements(float a[], unsigned n)
{
	float sum = 0;
	for(unsigned i = 0; i <= n-1; ++i)
	  sum += a[i];
	return sum;
}

static float a[2] = {0, 1};

int main()
{
	cout << sum_elements(a, 0) << endl;
	return 0;
}
