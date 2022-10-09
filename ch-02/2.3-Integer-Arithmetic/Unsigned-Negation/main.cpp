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
	enum uint64_t{value=pow2<sizeof(U) * 8>::value};
};

template<typename U>
U negation(U u)
{//modular addtion:negation
	if(u==0) return 0;
	else return max_unsigned<U>::value - u;
}

int main()
{
	cout << "negation(2u):" << negation(2u) << endl;
	cout << "negation(2u) + 2u:" << negation(2u) + 2u << endl;
	return 0;
}
