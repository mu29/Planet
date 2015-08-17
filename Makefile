CXX = g++ -std=c++11

SRCS = lib/json/json.cpp lib/json/reader.cpp lib/json/writer.cpp lib/string/split.cpp \
src/request.cpp src/response.cpp src/router.cpp src/url_dispatcher.cpp src/main.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = bin/main.fcgi

LIBS = -lfcgi

.SUFFIXES: .cpp .o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

clean :
	rm $(OBJS)

