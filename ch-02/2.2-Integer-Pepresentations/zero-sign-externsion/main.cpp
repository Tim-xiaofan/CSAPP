#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

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

int main()
{
	short sx = -12345;
	unsigned short usx = sx;
	int x = sx;
	unsigned ux = usx;

	cout << "sx:" << sx << "\t" << bytes_to_bits(&sx, sizeof(sx)) << endl;
	cout << "usx:" << usx << "\t" << bytes_to_bits(&usx, sizeof(sx)) << endl;
	cout << "x:" << x << "\t" << bytes_to_bits(&x, sizeof(x)) << endl;
	cout << "ux:" << ux << "\t" << bytes_to_bits(&ux, sizeof(ux)) << endl;
	return 0;
}
