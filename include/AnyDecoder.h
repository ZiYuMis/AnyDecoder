#ifndef __ANYDECODER__
#define __ANYDECODER__

#include <iostream>
#include "OutObj.h"


class AnyDecoder
{
public:
    AnyDecoder();
    ~AnyDecoder();
    virtual void done();
    void setOutObj(OutObj* pOutObj);
    void setInputStr(std::string strInput);

private:
    std::string m_strInput;
    OutObj* m_pOutObj;
};

#endif //__ANYDECODER__
