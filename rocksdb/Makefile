CXX=g++ -std=c++11
CXXFLAGS=-lrocksdb  # 注意添加链接库

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: main
	./main

clean:
	rm -f main *.o

