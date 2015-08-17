#include "../lib/json/lightjson.h"
#include "../lib/string/split.h"

#include "router.h"
#include "url_dispatcher.h"
#include "fcgi_stdio.h"

void LoadFunctions();

int main() {
    Router* router = Router::GetInstance();
    UrlDispatcher* urlDispatcher = UrlDispatcher::GetInstance();
    LoadFunctions();

    while (FCGI_Accept() >= 0) {
        Request request = urlDispatcher->GetRequest();
        router->Handle(request);
        printf("Content-type:text/html \r\n\r\n hi");
    }
    return 0;
}

void LoadFunctions() {

}
