#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using std::cout;
using std::endl;
using std::string;

bool add_ok(unsigned short a, unsigned short b)
{
	return (static_cast<unsigned short>(a + b) >= b) && 
		(static_cast<unsigned short>(a + b) >= a);
}

int main()
{
	cout << "In unsigned short:\n";
	cout << "3000 + 4000 add ok? " << 
		std::boolalpha << add_ok(3000, 4000) << endl;
	cout << "30000 + 40000 add ok? " << 
		std::boolalpha << add_ok(30000, 40000) << endl;
	return 0;
}
