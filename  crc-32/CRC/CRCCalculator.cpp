#include "CRCCalculator.h"

#include <string.h> //For memcpy


CRCCalculator::CRCCalculator()
:m_crc(0)
{
}

CRCCalculator::~CRCCalculator()
{
}


/******************************************************************************************
*
* This function implemented CRC32 Ethernet algorithm
* TODO add comments
*
******************************************************************************************/
const uint32_t CRCCalculator::CalculateCRC32(const uint8_t* message, const unsigned int len)
{
	unsigned int byte, crc, mask;

	crc = 0xffffffff;

	//while ( message[i] != 0 )
	for (unsigned int i = 0; i < len; i++)
	{
		byte = message[i];      //Get next byte

		crc = crc ^ byte;

		for (int j=7; j>=0; j--)
		{
			mask = -(crc &1);
			crc = (crc >> 1) ^ (0xedb88320 & mask);
		}
		//i = i + 1;
	}

	this->m_crc = ~crc;
	return ~crc;
}

uint8_t* CRCCalculator::AppendCRC32(uint8_t* where, const unsigned int len)
{
	//CRC32
	uint32_t crc = CRCCalculator::CalculateCRC32(where,len);

    uint8_t* temp = new uint8_t[sizeof(uint32_t)];
    memcpy(temp,&crc,sizeof(uint32_t) / sizeof(uint8_t));
    //shifting
    //Move to end of buffer
    where += len;
    for (unsigned int i = 0; i < sizeof(uint32_t); i++)
    {
        where[i] = temp[i];
    }
    where += sizeof(uint32_t);

    delete temp;
    return where;
}
