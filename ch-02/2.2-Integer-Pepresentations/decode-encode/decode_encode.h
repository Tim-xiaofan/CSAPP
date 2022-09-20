#ifndef _DECODE_ENCODE_H_
#include <iostream>
#include <string>

namespace decode_encode
{
	using std::uint64_t;
	using std::int64_t;
	using bit_t = std::uint8_t;
	using std::string;
	/** 无符号整数*/
	uint64_t B2U(const string& bits);
	/** 有符号：补码*/
	int64_t B2T(const string& bits);
	string T2B(int64_t i);//整数-->补码
	string O2B(int64_t i);//整数-->反码
	string S2B(int64_t i);//整数-->原码
	const bit_t BIT_1 = '1';
	const bit_t BIT_0 = '0'; 

	string & increase_bits(string & bits);
	static inline bit_t bit_xor(bit_t a, bit_t b)
	{
		return (a != b) ?BIT_1:BIT_0;
	}

	static inline bit_t bit_and(bit_t a, bit_t b)
	{
		return (a == BIT_1 && b == BIT_1)?BIT_1:BIT_0;
	}
	
	static inline bit_t bit_add(bit_t a, bit_t b, bit_t &sum)
	{
		sum = bit_xor(a, b);
		return bit_and(a, b);
	}
}

#endif
