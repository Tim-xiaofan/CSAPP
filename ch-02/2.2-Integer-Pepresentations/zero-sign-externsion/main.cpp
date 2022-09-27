#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <array>

using std::cout;
using std::string;
using std::endl;
using std::uint8_t;

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
bytes_to_bits(void *bytes, size_t n)
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

static std::string
dump_bytes(void *bytes, size_t n)
{
	uint8_t *tmp = reinterpret_cast<uint8_t *>(bytes);
	int tot = n * 2 + 1, used = 0;
	char *buf = new char[tot];
	std::memset(buf, 0, tot);

	if(buf != nullptr)
	{
		if(!is_little_endien())
		{
			for(size_t i = 0; i < n; ++i)
				used += snprintf(&buf[used], tot - used, "%02x", tmp[i]);
		}
		else
		{
			for(int i = n - 1; i>=0; --i)
				used += snprintf(&buf[used], tot - used, "%02x", tmp[i]);
		}
		string ret(buf);
		delete []buf;
		return ret;
	}
	else
	  return string("");
}

int fun1(unsigned word)
{
	return (int) ((word << 24) >> 24); // 逻辑右移
}

int fun2(unsigned word)
{
	return (((int)word << 24) >> 24); // 算数右移
}

int main()
{
	short sx = -12345;
	unsigned short usx = sx;	// 53129
	int x = sx;					// -12345
	unsigned ux = usx;			// 53191

	cout << "sx:" << sx << "\t" << bytes_to_bits(&sx, sizeof(sx)) << endl;
	cout << "usx:" << usx << "\t" << bytes_to_bits(&usx, sizeof(sx)) << endl;
	cout << "x:" << x << "\t" << bytes_to_bits(&x, sizeof(x)) << endl;
	cout << "ux:" << ux << "\t" << bytes_to_bits(&ux, sizeof(ux)) << endl;

	unsigned uy = sx;	//Mystery
	cout << "uy:" << uy << "\t" << bytes_to_bits(&uy, sizeof(uy)) << endl;

	// Practice Problem 2.23
	cout << endl;
	std::array<unsigned, 4> ia = {0x76, 0x87654321, 0xc9, 0xEDCBA987};
	printf("w       \tfun1    \tfun2\n");
	for(unsigned &i : ia)
	{
		cout << dump_bytes(&i, sizeof(i)) << '\t';
		int tmp = fun1(i);
		cout << dump_bytes(&tmp, sizeof(tmp)) << '\t';
		tmp = fun2(i);
		cout << dump_bytes(&tmp, sizeof(tmp)) << '\n';
	}

	cout << endl;
	int i = -2;
	printf("(%d << 2) = %d\n", i, i << 2);
	return 0;
}
