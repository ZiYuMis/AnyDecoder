#include "../include/URLEncoder.h"


URLEncoder::URLEncoder()
{
}

URLEncoder::~URLEncoder()
{
}

void URLEncoder::done()
{
    std::string result = "";
    for (unsigned int i = 0; i < m_strInput.size(); i++)
    {
        char c = m_strInput[i];
        if (
            ('0' <= c && c <= '9') ||
            ('a' <= c && c <= 'z') ||
            ('A' <= c && c <= 'Z') ||
            c == '/' || c == '.')
        {
            result += c;
        }
        else
        {
            int j = (short int)c;
            if (j < 0)
            {
                j += 256;
            }
            int i1, i0;
            i1 = j / 16;
            i0 = j - i1 * 16;
            result += '%';
            result += dec2hexChar(i1);
            result += dec2hexChar(i0);
        }
    }

        if(m_pOutObj != NULL)
    {
        m_pOutObj->outData(result);
    }

}
