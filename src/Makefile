main.fcgi : main.o request.o response.o router.o url_dispatcher.o
	g++ -o main.fcgi main.cpp -lfcgi

request.o : request.cpp request.h
	g++ -c request.cpp

response.o : response.cpp response.h
	g++ -c response.cpp -std=c++11

router.o : router.cpp router.h
	g++ -c router.cpp

url_dispatcher.o : url_dispatcher.cpp url_dispatcher.h
	g++ -c url_dispatcher.cpp -std=c++11

main.o : main.cpp
	g++ -c main.cpp

