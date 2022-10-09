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
	enum:std::int64_t{value=2 * pow2<n-1>::value};
};

template<>
struct pow2<0>
{
	enum:std::int64_t {value=1};
};

template <typename U>
struct max_signed
{
	enum int64_t{value=pow2<sizeof(U) * 8 - 1>::value - 1};
};

template <typename U>
struct min_signed
{
	enum int64_t{value=-pow2<sizeof(U) * 8 - 1>::value};
};

const short TMax = max_signed<short>::value;
const short TMin = min_signed<short>::value;


static bool 
tadd_ok(short a, short b)
{
	return !(( a > 0 && b > 0 && static_cast<short>(a + b) < 0) || 
		(a < 0 && b < 0 && static_cast<short>(a + b) > 0));
}

int main()
{
	cout << "In short:\n";
	unsigned us = 32768; 
	int i = -us;
	cout << i << endl;
	cout << "TMax:" << TMax << endl;
	cout << "TMin:" << TMin << endl;
	cout << "TMax + 1:" << static_cast<short>(TMax + (short)1) << endl;
	cout << "TMin + (-1):" << static_cast<short>(TMin + (short)-1) << endl;

	cout << "\n3000 + 4000 = " << static_cast<short>(3000 + 4000) << endl;
	cout << "3000 + 4000 add ok? " << 
		std::boolalpha << tadd_ok(3000, 4000) << endl;

	cout << "\n-3000 + (-4000) = " << static_cast<short>(-3000 + -4000) << endl;
	cout << "-3000 + -4000 add ok? " << 
		std::boolalpha << tadd_ok(-3000, -4000) << endl;
	
	cout << "\n30000 + 30000 = " << static_cast<short>(30000 + 30000) << endl;
	cout << "30000 + 30000 add ok? " << 
		std::boolalpha << tadd_ok(30000, 30000) << endl;


	cout << "\n-30000 + -30000 = " << static_cast<short>(-30000 + -30000) << endl;
	cout << "-30000 + -30000 add ok? " << 
		std::boolalpha << tadd_ok(-30000, -30000) << endl;

	return 0;
}
