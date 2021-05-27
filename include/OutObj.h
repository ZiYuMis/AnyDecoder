#ifndef __OUTOBJ_H__
#define __OUTOBJ_H__

#include <string>
#include <iostream>
#include <fstream>

class OutObj
{
public:
    OutObj();
    ~OutObj();
    void setFileName(std::string strFilName);
    void outData(std::string strOut);

private:
    bool m_bIsCmd;
    std::string m_strFileName;
    
};

#endif //__OUTOBJ_H__