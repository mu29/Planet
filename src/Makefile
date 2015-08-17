main.fcgi : main.o request.o response.o
	g++ -o main.fcgi main.cpp -lfcgi

request.o : request.cpp request.h
	g++ -c request.cpp

response.o : response.cpp response.h
	g++ -c response.cpp -std=c++11

main.o : main.cpp
	g++ -c main.cpp

