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
    
    if (method == "GET") {
        std::vector<std::string> params = split(getenv("QUERY_STRING"), '&');
        
        for (std::string i : params) {
            std::vector<std::string> keyValue = split(i, '=');
            if (keyValue.size() == 2)
                parameter[keyValue[0]] = keyValue[1];
        }
    }

    char buf[2048];
    memset(buf, 0, 2048);
    fread(buf, sizeof(char), 2048, stdin);

    body = reader.decode(buf);
    Request req(route, method, parameter, body);
    return req;
}

