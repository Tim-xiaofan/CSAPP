#include <iostream>

using std::cout;
using std::endl;
using std::uint8_t;

/**
  一个运算数是有符号的而另一个是无符号的，那么
  语言会隐式地将有符号参数强制类型转换为无符号
 */

int main()
{
	cout << "-1 * 1U\t" << std::boolalpha << (-1 * 1U) << endl;
	cout << "0 == 0U\t" << std::boolalpha << (0 == 0U) << endl;
	cout << "0 == 0\t" << std::boolalpha << (0 == 0) << endl;
	cout << "-1 < 0U\t" << std::boolalpha << (-1 == 0U) << endl;
	cout << "2147483647 < -2147483647-1\t" << std::boolalpha << (2147483647 < (-2147483647-1)) << endl;
	cout << "2147483647U < -2147483647-1\t" << std::boolalpha << (2147483647U < (-2147483647-1)) << endl;
	cout << "-1 < -2\t" << std::boolalpha << (-1 == -2) << endl;
	cout << "(unsigned)-1 < -2\t" << std::boolalpha << ((unsigned)-1 == (int)-2) << endl;
	return 0;
}
