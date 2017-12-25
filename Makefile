# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g

all: maxBWPath

maxBWPath: maxBW.cc dijkstra.cc main.cc maxHeap.cc randGraph.cc dijkstraNoHeap.cc kruskal.cc graph.h maxHeap.h randGraph.h maxBW.h
	$(CC) $(CFLAGS) -o maxBWPath maxBW.cc dijkstra.cc main.cc maxHeap.cc randGraph.cc dijkstraNoHeap.cc kruskal.cc

clean:
	$(RM) main

