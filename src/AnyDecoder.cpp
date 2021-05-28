#include "../include/AnyDecoder.h"

AnyDecoder::AnyDecoder()
{
    m_pOutObj = NULL;
}

AnyDecoder::~AnyDecoder()
{
    
}


void AnyDecoder::setOutObj(OutObj* pOutObj)
{
    m_pOutObj = pOutObj;
}

void AnyDecoder::setInputStr(std::string strInput)
{
    m_strInput = strInput;
}


void AnyDecoder::done()
{
    if(m_pOutObj != NULL)
    {
        m_pOutObj->outData(m_strInput);
    }
}

char AnyDecoder::dec2hexChar(short int n)
{
    if (0 <= n && n <= 9)
    {
        return char(short('0') + n);
    }
    else if (10 <= n && n <= 15)
    {
        return char(short('A') + n - 10);
    }
    else
    {
        return char(0);
    }
}

short AnyDecoder::hexChar2dec(char c)
{
    if ('0' <= c && c <= '9')
    {
        return short(c - '0');
    }
    else if ('a' <= c && c <= 'f')
    {
        return (short(c - 'a') + 10);
    }
    else if ('A' <= c && c <= 'F')
    {
        return (short(c - 'A') + 10);
    }
    else
    {
        return -1;
    }
}