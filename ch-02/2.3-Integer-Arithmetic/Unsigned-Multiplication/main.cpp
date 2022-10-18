#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using std::cout;
using std::endl;
using std::string;

template<unsigned n>
struct pow2
{
	enum:std::uint64_t{value=2 * pow2<n-1>::value};
};

template<>
struct pow2<0>
{
	enum:std::uint64_t {value=1};
};

template <typename U>
struct max_unsigned
{
	enum uint64_t{value=pow2<sizeof(U) * 8>::value - 1};
};

static const unsigned short UMax = max_unsigned<unsigned short>::value;

template<typename I>
static bool imult_ok(I x, I y)
{
	I p = x * y;
	return !x || p /x == y;
}

int main()
{
	cout << "UMax:" << UMax << endl;
	cout << "UMax * 2:" << std::boolalpha << imult_ok(UMax, (unsigned short)2) << endl;
	cout << "UMax * 0:" << std::boolalpha << imult_ok(UMax, (unsigned short)0) << endl;
	cout << "1000 * 10:" << std::boolalpha << 
		imult_ok((unsigned short)1000, (unsigned short)10) << endl;
	cout << "1000 * 100:" << std::boolalpha << 
		imult_ok((unsigned short)1000, (unsigned short)100) << endl;
	return 0;
}
