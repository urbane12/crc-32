/*
 * Main.cpp
 *
 *  Created on: Sep 22, 2008
 *      Author: svc
 */


#include <iostream>
using namespace std;

#include "CRCCalculator.h"

int main()
{
	CRCCalculator* crc32 = new CRCCalculator();

	uint8_t* message = new uint8_t[ sizeof(uint8_t) * 1514];
		message[0]  = 0x88;
	    message[1]  = 0x88;
	    message[2]  = 0x88;
	    message[3]  = 0x88;
	    message[4]  = 0x87;
	    message[5]  = 0x88;
	    message[6]  = 0x01;
	    message[7]  = 0x02;
		message[8]  = 0x03;
	    message[9]  = 0x04;
	    message[10] = 0x05;
	    message[11] = 0x06;
	    message[12] = 0x05;
	    message[13] = 0xdc;

	    uint8_t value = 0x00;

	    for(int i = 14; i < 1514; i++)
	    {
	   	    message[i] = value;
	   	    value++;
	    }


	 	const uint32_t crc = crc32->CalculateCRC32(message,1514);

		//Debug
		//printf("The CRC-32 value: 0x%08x  \n", crc);

	    uint8_t* point = (uint8_t*)& crc;
		for(unsigned int i = 0; i < sizeof(uint32_t); i++)
	     	printf("0x%02x ", point[i]);

		if (message) delete message;
		if (crc32) delete crc32;

		return 1;

}
