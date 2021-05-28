#ifndef __URLDECODER_H__
#define __URLDECODER_H__

#include "AnyDecoder.h"

class URLDecoder :public AnyDecoder
{
public:
	URLDecoder();
	~URLDecoder();

    virtual void done();
 
 
private:
	
};



#endif //__URLDECODER_H__