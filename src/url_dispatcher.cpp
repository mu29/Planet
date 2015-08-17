#include "url_dispatcher.h"

UrlDispatcher::UrlDispatcher() { }

UrlDispatcher* UrlDispatcher::GetInstance() {
    return &instance_;
}

Request UrlDispatcher::GetRequest() {
    std::string route = std::getenv("SCRIPT_NAME");
    std::string method = std::getenv("REQUEST_METHOD");
    Json::Object parameter;
    Json::Object body;
    Json::Reader reader;

    char buf[2048];
    memset(buf, 0, 2048);
    fread(buf, sizeof(char), 2048, stdin);

    body = reader.decode(buf);
    Request req(route, method, parameter, body);
    return req;
}

