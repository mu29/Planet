#include "request.h"

Request::Request(string route, string method, Json::Object parameter, Json::Object body) {
    route_ = route;
    method_ = method;
    parameter_ = parameter;
    body_ = body;
}

string Request::getRoute() {
    return route_;
}

string Request::getMethod() {
    return method_;
}

Json::Object& Request::getParameter() {
    return parameter_;
}

Json::Object Request::getBody() {
    return body_;
}
