#include "../lib/json/lightjson.h"
#include "../lib/string/split.h"

#include "router.h"
#include "url_dispatcher.h"
#include "fcgi_stdio.h"

void LoadFunctions();
void testGET(Request req);
void testPOST(Request req);

int main() {
    Router* router = Router::GetInstance();
    UrlDispatcher* urlDispatcher = UrlDispatcher::GetInstance();
    LoadFunctions();

    while (FCGI_Accept() >= 0) {
        Request request = urlDispatcher->GetRequest();
        router->Handle(request);
    }
    return 0;
}

void LoadFunctions() {
    Response rTestGET("/test", "GET", testGET);
    Response rTestPOST("/test", "POST", testPOST);
    Router* router = Router::GetInstance();
    router->AddResponse(rTestGET);
    router->AddResponse(rTestPOST);
}

void testGET(Request req) {
    string param = req.GetParameter()["param"].toString();
    printf("Content-type: text/json \r\n\r\n %s kkk", param.c_str());
}

void testPOST(Request req) {
    string body = req.GetBody()["body"].toString();
    printf("Content-type: text/json \r\n\r\n %s", body.c_str());
}

