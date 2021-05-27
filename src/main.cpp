#include "../include/DecoderFactory.h"
#include "../include/ParamDeal.h"

using namespace std;

int main(int argc, char *argv[])
{
    ParamDeal pd;
    if (true == pd.dealParam(argc, argv))
    {
        DecoderFactory factory;
        factory.setDecoderParam(pd.getDecoderParam());
        factory.decode();
    }

    return 0;
}
