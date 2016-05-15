all: main

city.h: city.o
	g++ -c city.cpp

astar.h: astar.o
	g++ -c astar.cpp 

main: city.h astar.h
	g++ main.cpp city.o astar.o -o a-estrela -g

clean:
	rm -rf city.o astar.o a-estrela
