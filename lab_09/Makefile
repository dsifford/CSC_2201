CC = g++
DEBUG = -g -Wextra
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

LAB_NUM = 9

all: build

build: bootstrap BSTree.o show9.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/test$(LAB_NUM) build/BSTree.o build/show9.o test$(LAB_NUM).cpp 

BSTree.o: BSTree.cpp BSTree.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

show9.o: show9.cpp BSTree.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -rf $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test$(LAB_NUM)