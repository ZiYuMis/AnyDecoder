#ifndef __DecoderFactory__
#define __DecoderFactory__

#include "TypeList.h"
#include "AnyDecoder.h"
#include "OutObj.h"

#include <sstream>

class DecoderFactory
{
public:
    DecoderFactory();
    ~DecoderFactory();
    void setDecoderParam(TypeList* pTypeList);
    void decode();

private:
    OutObj* m_pOutObj;
    TypeList* m_pTypeList;
    AnyDecoder* m_pAnyDecoder;
};

#endif //__DecoderFactory__