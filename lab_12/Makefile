CC = g++
DEBUG = -g -Wextra
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

LAB_NUM = 12

all: bootstrap build

build: test12.cpp WeightedGraph.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/test$(LAB_NUM) build/WeightedGraph.o test12.cpp

WeightedGraph.o: WeightedGraph.cpp WeightedGraph.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

.PHONY: bootstrap
bootstrap:
	@ mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@ rm -rf $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test$(LAB_NUM)