#include "response.h"

Response::Response(std::string route, std::string method, void(*handler)(Request)) {
    route_ = route;
    method_ = method;
    handler_ = handler;
}

std::string Response::GetRoute() {
    return route_;
}

bool Response::IsMatch(Request& req) {
    if (req.GetMethod() != method_)
        return false;

    return true;
}

void Response::Execute(Request req) {
    handler_(req);
}
