CC = g++
DEBUG = -g -Wextra
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

LAB_NUM = 8

all: build

build: bootstrap ExpressionTree.o
	$(CC) $(LFLAGS) -o $(BIN_PATH)/test$(LAB_NUM) build/ExpressionTree.o test$(LAB_NUM).cpp 

ExpressionTree.o: ExpressionTree.cpp ExpressionTree.h
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

.PHONY: debug
debug:
	@ gdb ./bin/test$(LAB_NUM)