#include "decode_encode.h"
#include <cctype>
#include <stack>
#include <cstdlib>

namespace decode_encode
{
	
	static uint64_t pow_of_2(uint64_t n)
	{
		uint64_t ret = 1;
		for(uint64_t i = 0; i < n; ++i)
		  ret *= 2;
		return ret;
	}

	static bool inline 
	is_bit(int c)
	{
		return (c == BIT_0 || c == BIT_1);
	}

	uint64_t B2U(const string& bits)
	{
		std::size_t n = bits.length();
		uint64_t ret = 0;
		for(std::size_t i = 0, w = n - 1; i < n; ++i, --w)
		  if(is_bit(bits[i]))
		  {
			  if(bits[i] != BIT_0)
				  ret += pow_of_2(w);
		  }
		  else
			return 0;
		return ret;
	}


	int64_t B2T(const string& bits)
	{
		std::size_t n = bits.length();
		int64_t ret = 0;
		for(std::size_t i = 0, w = n - 1; i < n; ++i, --w)
		  if(is_bit(bits[i]))
		  {
			  if(bits[i] != BIT_0)
			  {
				  if(i != 0)
					ret += pow_of_2(w);
				  else //最高位
					ret += -pow_of_2(w);
			  }
		  }
		  else
			return 0;
		return ret;
	}
	
	string S2B(int64_t i)
	{//整数-->原码
		string bits;
		uint8_t s = (i < 0) ?BIT_1:BIT_0;//符号位
		bits.push_back(s);

		std::stack<uint8_t> remains;
		uint64_t tmp = std::llabs(i);
		while(tmp != 0)
		{
			remains.push(BIT_0 + tmp % 2);
			tmp = tmp / 2;
		}
		while(!remains.empty())
		{
			bits.push_back(remains.top());
			remains.pop();
		}
		return bits;
	}

	string O2B(int64_t i)
	{//整数->反码
		string S = std::move(S2B(i));//原码
		if(i < 0)
		{
			for(std::size_t i = 1; i < S.length(); ++i)
			  S[i] = (S[i] == BIT_0) ? BIT_1:BIT_0;
		}
		return S;
	}

	string & increase_bits(string & bits)
	{
		bit_t c, sum;
		c = bit_add(bits[bits.length() - 1], BIT_1, sum);
		bits[bits.length() - 1] = sum;
		for(int i = bits.length() - 2; i >=0  && c != BIT_0; --i)
		{
			c = bit_add(bits[i], c, sum);
			bits[i] = sum;
		}
		if(c == BIT_1)
		  bits = "1" + bits;
		return bits;
	}

	string T2B(int64_t i)
	{
		if(i >=0) return S2B(i);
		else
		{
			string O = std::move(O2B(i)); //求反码
			increase_bits(O); 
			return O;
		}
	}
}
