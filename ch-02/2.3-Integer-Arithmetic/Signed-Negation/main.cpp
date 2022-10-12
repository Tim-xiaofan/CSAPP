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


template<typename T>
static T negation(T x)
{//method 1
	return ~x + 1;
}

template<typename T>
static T negation1(T x)
{//method 2
	if(min_signed<T>::value == x)
	  return min_signed<T>::value;
	else
	  return -x;
}

int main()
{
	cout << "TMin:" << TMin << endl;
	cout << "TMax:" << TMax << endl;
	cout << "negation(TMin):" << negation(TMin) << endl;
	cout << "negation1(TMin):" << negation1(TMin) << endl;
	cout << "negation(TMax):" << negation(TMax) << endl;
	cout << "negation1(TMax):" << negation1(TMax) << endl;
	cout << "negation(0):" << negation((short)0) << endl;
	cout << "negation1(0):" << negation1((short)0) << endl;
	cout << "negation(-1):" << negation((short)-1) << endl;
	cout << "negation1(-1):" << negation1((short)-1) << endl;
	return 0;
}
