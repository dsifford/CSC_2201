CC = g++
DEBUG = -g -Wextra 
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

LAB_NUM = 11

all: bootstrap buildheapsort

build: Heap.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/test$(LAB_NUM) $(BUILD_PATH)/Heap.o test$(LAB_NUM).cpp 

buildpq: PriorityQueue.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/test$(LAB_NUM)pq $(BUILD_PATH)/PriorityQueue.o test$(LAB_NUM)pq.cpp 

buildossim: PriorityQueue.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/ossim $(BUILD_PATH)/PriorityQueue.o ossim.cpp 

buildheapsort: heapsort.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/heapsort $(BUILD_PATH)/heapsort.o test11hs.cpp

Heap.o: Heap.cpp show11.cpp Heap.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

PriorityQueue.o: PriorityQueue.cpp Heap.o PriorityQueue.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

heapsort.o: heapsort.cpp
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -rf $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	# @ ./bin/test$(LAB_NUM)pq
	# @ ./bin/ossim
	@ ./bin/heapsort