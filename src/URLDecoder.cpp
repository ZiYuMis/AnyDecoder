#include "../include/URLDecoder.h"



URLDecoder::URLDecoder()
{
}

URLDecoder::~URLDecoder()
{
}

void URLDecoder::done()
{
    std::string result = "";
    for (unsigned int i = 0; i < m_strInput.size(); i++)
    {
        char c = m_strInput[i];
        if (c != '%')
        {
            result += c;
        }
        else
        {
            char c1 = m_strInput[++i];
            char c0 = m_strInput[++i];
            int num = 0;
            num += hexChar2dec(c1) * 16 + hexChar2dec(c0);
            result += char(num);
        }
    }

    if (m_pOutObj != NULL)
    {
        m_pOutObj->outData(result);
    }
}
