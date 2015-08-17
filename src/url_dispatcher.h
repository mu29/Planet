#ifndef __server__url__dispatcher__
#define __server__url__dispatcher__

#include "../lib/string/split.h"

#include <string.h>
#include "fcgi_stdio.h"
#include "request.h"

class UrlDispatcher {
private:
    static UrlDispatcher* instance_;
    UrlDispatcher();
    
public:
    static UrlDispatcher* GetInstance();
    Request GetRequest();
};

#endif /* defined(__server__url__dispatcher__) */
