#include "decode_encode.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using std::size_t;
using std::uint8_t;
using namespace decode_encode;

static array<string, 4> int_strs= {"0001", "0101", "1011", "1111"};
static array<int, 4> ints= {8, -8, -1, 0};

#define BITS_FMT "%d%d%d%d%d%d%d%d"
#define BYTE2BITS(B) \
	((uint8_t)(B) & 0x80) >>7,\
	((uint8_t)(B) & 0x40) >>6,\
	((uint8_t)(B) & 0x20) >>5,\
	((uint8_t)(B) & 0x10) >>4,\
	((uint8_t)(B) & 0x08) >>3,\
	((uint8_t)(B) & 0x04) >>2,\
	((uint8_t)(B) & 0x02) >>1,\
	((uint8_t)(B) & 0x01) >>0

bool is_little_endien(void)
{
	union 
	{
		uint8_t a;
		uint32_t b;
	}s;
	s.b = 1;
	return (s.a == 1);
}

static std::string
B2b(void *bytes, size_t n)
{// 以大端形式输出
	uint8_t *tmp = reinterpret_cast<uint8_t *>(bytes);
	int tot = n * 8 + 1, used = 0;
	char *buf = new char[tot];
	std::memset(buf, 0, tot);

	if(buf != nullptr)
	{
		if(!is_little_endien())
		{
			for(size_t i = 0; i < n; ++i)
				used += snprintf(&buf[used], tot - used, BITS_FMT, BYTE2BITS(tmp[i]));
		}
		else
		{
			for(int i = n - 1; i >=0 ; --i)
				used += snprintf(&buf[used], tot - used, BITS_FMT, BYTE2BITS(tmp[i]));
		}
		string ret(buf);
		delete []buf;
		return ret;
	}
	else
	  return string("0");
}

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
		cout << bits  << " + 1 = " << increase_bits(bits) << endl;
	}

	cout << endl;
	std::printf("int\t原码\t反码\t补码\t检查\n");
	for(int & i: ints)
	{
		cout << i <<"\t";
		cout << S2B(i) << "\t";
		cout << O2B(i) << "\t";
		cout << T2B(i) << "\t";
		cout << B2T(T2B(i)) << "\n";
	}

	cout << endl;
	array<short, 2> as = {12345, -12345};
	std::printf("int\t补码\t\tbits\t\t\t检查\n");
	for(short & x: as)
	{
		cout <<  x << '\t';
		cout << T2B(x) << '\t';
		cout  << B2b(&x, sizeof(x)) << '\t';
		cout  << B2T(B2b(&x, sizeof(x))) << endl;
	}

	return 0;
}
