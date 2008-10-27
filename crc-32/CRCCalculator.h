#ifndef CRCCALCULATOR_H_
#define CRCCALCULATOR_H_

#include <stdint.h>

class CRCCalculator
{
public:
    //Constructors
	CRCCalculator();

	virtual ~CRCCalculator();

    virtual const uint32_t CalculateCRC32(const uint8_t* message, const unsigned int len);

    virtual uint8_t* AppendCRC32(uint8_t* where, const unsigned int len);

private:
    //Forbid copy constructor, assignment operator
    CRCCalculator(const CRCCalculator& copy);
    CRCCalculator& operator=(const CRCCalculator& assign);

    //CRC-32 located
    uint32_t m_crc;

};


#endif /*CRCCALCULATOR_H_*/



