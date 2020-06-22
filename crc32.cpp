#include "crc32.h"



crc32::crc32()
{
}


crc32::~crc32()
{
}


UINT32 crc32::getCRC(unsigned char* buf, int nLength)
{
	if (nLength < 1)
		return 0xffffffff;

	UINT32 crc = 0;

	for (int i(0); i != nLength; ++i)
	{
		crc = table[(crc ^ buf[i]) & 0xff] ^ (crc >> 8);
	}

	crc = crc ^ 0xffffffff;

	return crc;
}

uint16_t crc32::CRC16(uint8_t* dataIn, int length)
{
	uint16_t result = 0;
	uint16_t tableNo = 0;

	for (int i = 0; i < length; i++)
	{
		tableNo = ((result & 0xff) ^ (dataIn[i] & 0xff));
		result = ((result >> 8) & 0xff) ^ CRC16Table[tableNo];
	}

	return result;
}