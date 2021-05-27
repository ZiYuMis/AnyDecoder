#include "../include/OutObj.h"


OutObj::OutObj()
{
    m_bIsCmd = true;
    m_strFileName = "Decode.txt";
}

OutObj::~OutObj()
{

}

void OutObj::setFileName(std::string strFilName)
{
    m_bIsCmd = false;
    m_strFileName = strFilName;
}


void OutObj::outData(std::string strOut)
{
    if(true == m_bIsCmd)
    {
        std::cout<<strOut<<std::endl;
    }
    else
    {
        if(m_strFileName.size() != 0)
        {
            std::ofstream outfile;
            outfile.open(m_strFileName, std::ios::out | std::ios::trunc);
            outfile<<strOut<<std::endl;
            outfile.close();
        }
    }
}