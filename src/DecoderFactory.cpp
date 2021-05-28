#include "../include/DecoderFactory.h"

#include <algorithm>  
#include <string.h>

DecoderFactory::DecoderFactory()
{
    m_pOutObj = NULL;
    m_pAnyDecoder = NULL;
    
}

DecoderFactory::~DecoderFactory()
{
    if(m_pOutObj != NULL)
    {
        delete m_pOutObj;
        m_pOutObj =NULL;
    }

    if(m_pAnyDecoder != NULL)
    {
        delete m_pAnyDecoder;
        m_pAnyDecoder = NULL;
    }

}

void DecoderFactory::setDecoderParam(TypeList* pTypeList)
{
    if(NULL != pTypeList)
    {
        std::string strInputData;
        if(true == pTypeList->m_bCmdIn)
        {
            strInputData = pTypeList->m_strCmdInput;
        }
        else
        {
            std::ifstream t(pTypeList->m_strInputFileName);
            std::stringstream buffer;
            buffer << t.rdbuf();
            strInputData = buffer.str();
        }

        m_pOutObj = new OutObj();
        if(false == pTypeList->m_bCmdOut)
        {
            m_pOutObj->setFileName(pTypeList->m_strOutputFileName);
        }

        std::transform(pTypeList->m_strType.begin(), pTypeList->m_strType.end(), pTypeList->m_strType.begin(), ::tolower);

        if(0==strcmp(pTypeList->m_strType.c_str(),"url"))
        {
            if(true == pTypeList->m_bIsDecoder)
            {
                m_pAnyDecoder = new URLDecoder();
            }
            else
            {
                m_pAnyDecoder = new URLEncoder();
            }
            
        }

        m_pAnyDecoder->setInputStr(strInputData);
        m_pAnyDecoder->setOutObj(m_pOutObj);


    }
}

void DecoderFactory::decode()
{
    if(m_pAnyDecoder != NULL)
    {
        m_pAnyDecoder ->done();
    }
}