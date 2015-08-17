#ifndef __planet__request__
#define __planet__request__

#include "libs/json/lightjson.h"

#include <string>

class Request {
private:
    string route_;
    string method_;
    Json::Object parameter_;
    Json::Object body_;
public:
    Request();
    Request(string route, string method, Json::Object parameter, Json::Object body);
    string getRoute();
    string getMethod();
    Json::Object& getParameter();
    Json::Object getBody();
};

#endif /* defined(__planet__request__) */
