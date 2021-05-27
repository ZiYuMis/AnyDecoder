#include "../include/ParamDeal.h"

#include <stdlib.h>
#include <stdio.h>

ParamDeal::ParamDeal()
{
    m_typeList.m_bIsSetDecoder = false;
    m_typeList.m_bIsSetType = false;
    m_typeList.m_bCmdIn = true;
    m_typeList.m_bCmdOut = true;
}

ParamDeal::~ParamDeal()
{
}

bool ParamDeal::dealParam(int argc, char *argv[])
{
    int opt;                                  // getopt() 的返回值
    const char *optstring = "hedt:li:I:oO:"; // 设置短参数类型及是否需要参数

    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        switch (opt)
        {
        case 'h':
            showHelp();
            return false;
        case 'l':
            showTypelist();
            return false;
        case 'e':
            m_typeList.m_bIsDecoder = false;
            m_typeList.m_bIsSetDecoder = true;
            break;
        case 'd':
            m_typeList.m_bIsDecoder = true;
            m_typeList.m_bIsSetDecoder = true;
            break;
        case 't':
            m_typeList.m_bIsSetType = true;
            m_typeList.m_strType = optarg;
            if(0 == m_typeList.m_strType.size())
            {
                std::cout<<"请输入加解密类型"<<std::endl;
                return false;
            }
            break;
        case 'i':
            m_typeList.m_bCmdIn = true;
            m_typeList.m_strCmdInput = optarg;
            break;
        case 'I':
            m_typeList.m_bCmdIn = false;
            m_typeList.m_strInputFileName = optarg;
            if(m_typeList.m_strInputFileName.size() == 0)
            {
                std::cout<<"请输入文件名"<<std::endl;
                return false;
            }
            break;
        case 'o':
            m_typeList.m_bCmdOut = true;
            break;
        case 'O':
            m_typeList.m_bCmdOut = false;
            m_typeList.m_strOutputFileName = optarg;
            if(m_typeList.m_strOutputFileName.size()==0)
            {
                std::cout<<"请输入文件名"<<std::endl;
                return false;
            }

            break;
        default:
            showHelp();
            return false;
        }

        // printf("opt = %c\n", opt);                             // 命令参数，亦即 -a -b -c -d
        // printf("optarg = %s\n", optarg);                       // 参数内容
        // printf("optind = %d\n", optind);                       // 下一个被处理的下标值
        // printf("argv[optind - 1] = %s\n\n", argv[optind - 1]); // 参数内容
    }

    if (false == m_typeList.m_bIsSetDecoder )
    {
        std::cout<<"请选择加密还是解密"<<std::endl;
        return false;
    }
    else if (false  == m_typeList.m_bIsSetType)
    {
        std::cout<<"请设置加解密类型"<<std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

TypeList *ParamDeal::getDecoderParam()
{
    return &m_typeList;
}

void ParamDeal::showHelp()
{
    std::cout << "usage:        -h    help      显示帮助                  " << std::endl;
    std::cout << "              -e    encode    加密                     " << std::endl;
    std::cout << "              -d    decode    解密                     " << std::endl;
    std::cout << "              -t    type      加密或者解密方式           " << std::endl;
    std::cout << "              -l    list      列出支持的加解密类型        " << std::endl;
    std::cout << "              -i    input     命令行输入 （默认）                 " << std::endl;
    std::cout << "              -I    Input     从文件中读取  后跟文件名    " << std::endl;
    std::cout << "              -o    output    命令行输出 （默认）             " << std::endl;
    std::cout << "              -O    output    输出到文件 后跟文件名      " << std::endl;
}

void ParamDeal::showTypelist()
{
    std::cout << " Typelist:           None    " << std::endl;
    std::cout << "                             " << std::endl;
    std::cout << "                             " << std::endl;
}
