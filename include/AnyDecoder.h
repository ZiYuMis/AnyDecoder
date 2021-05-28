#ifndef __ANYDECODER__
#define __ANYDECODER__

#include <iostream>
#include "OutObj.h"

#include "../include/BeachRabbit.h"


class AnyDecoder
{
public:
    AnyDecoder();
    ~AnyDecoder();
    virtual void done();
    void setOutObj(OutObj* pOutObj);
    void setInputStr(std::string strInput);

protected:
    short hexChar2dec(char c);
    char dec2hexChar(short int n);
protected:
    std::string m_strInput;
    OutObj* m_pOutObj;
};

#endif //__ANYDECODER__
