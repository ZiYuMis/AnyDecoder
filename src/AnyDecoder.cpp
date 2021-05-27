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