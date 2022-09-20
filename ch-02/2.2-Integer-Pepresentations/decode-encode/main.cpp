#include "decode_encode.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using namespace decode_encode;

static array<string, 4> int_strs= {"0001", "0101", "1011", "1111"};
static array<int, 4> ints= {8, -8, -1, 0};

int main()
{
	for(string &bits:int_strs)
	{
		cout << "B2U("<< bits<< "):" << B2U(bits) << endl;
		cout << "B2T("<< bits<< "):" << B2T(bits) << endl;
		cout << endl;
	}

	bit_t sum, c;
	bit_t a[] = {BIT_0, BIT_1};
	for(int i = 0; i < 2; ++i)
	{
		for(int j =0; j < 2; ++j)
		{
			c = bit_add(a[i], a[j], sum);
			printf("%c + %c = %c, c = %c\n", a[i], a[j], sum, c);
		}
	}

	cout <<endl;
	for(string &bits:int_strs)
	{
		cout << bits  << ":" << increase_bits(bits) << endl;
	}

	std::printf("int\t原码\t反码\t补码\t检查\n");
	for(int & i: ints)
	{
		cout << i <<"\t";
		cout << S2B(i) << "\t";
		cout << O2B(i) << "\t";
		cout << T2B(i) << "\t";
		cout << B2T(T2B(i)) << "\n";
	}
	return 0;
}
