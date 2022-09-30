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
	enum {value=2 * pow2<n-1>::value};
};

template<>
struct pow2<0>
{
	enum {value=1};
};

template <typename U>
struct max_unsigned
{
	enum {value=pow2<sizeof(U) * 8>::value};
};

unsigned negation(unsigned u)
{//modular addtion:negation
	return 0;
}

int main()
{
	//cout << "max_unsigned<unsigned>:" << std::hex 
	//	<< max_unsigned<unsigned>::value << endl;
	return 0;
}
