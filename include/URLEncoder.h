#ifndef __URLEncode_H_
#define __URLEncode_H_

#include "AnyDecoder.h"

class URLEncoder :public AnyDecoder
{
public:
	URLEncoder();
	~URLEncoder();

    virtual void done();
  
private:
	
};








#endif //__URLEncode_H_