#ifndef __TYPELIST__
#define __TYPELIST__

#include <string>

enum EncoderTypeList
{
    m_null = 0,
    url =1,
    base64=2
};

struct TypeList
{
    bool m_bIsSetDecoder;
    bool m_bIsDecoder;   // 加解密器    true   解密器  false  加密器
    bool m_bIsSetType;
    EncoderTypeList m_eEncoderTypeList;
    bool m_bCmdIn;      // 输入方式    true   命令行  false  文件
    bool m_bCmdOut;     // 输出方式    true   命令行  false  文件
    std::string m_strType;
    std::string m_strCmdInput;
    std::string m_strInputFileName;
    std::string m_strOutputFileName;
};


#endif //__TYPELIST__