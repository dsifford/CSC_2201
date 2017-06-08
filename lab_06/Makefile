CC = g++
DEBUG = -g -Wextra
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

all: build

build: bootstrap StackArray.o StackLinked.o 
	$(CC) $(LFLAGS) build/StackArray.o build/StackLinked.o test6.cpp -o $(BIN_PATH)/test6

StackArray.o: StackArray.cpp StackArray.h Stack.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

StackLinked.o: StackLinked.cpp StackLinked.h Stack.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

show6.o: Stack.h StackLinked.h StackArray.h show6.cpp
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -f $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test6