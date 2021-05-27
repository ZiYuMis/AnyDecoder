#ifndef __PARAMDEAL__
#define __PARAMDEAL__

#include <unistd.h>
#include <iostream>

#include "TypeList.h"

class ParamDeal
{
public:
    ParamDeal();
    ~ParamDeal();
    bool dealParam(int argc, char *argv[]);
    TypeList *getDecoderParam();
private:

    void showHelp();
    void showTypelist();

private:
    TypeList m_typeList;
};

#endif //__PARAMDEAL__

//https://blog.csdn.net/qq_34719188/article/details/83788199