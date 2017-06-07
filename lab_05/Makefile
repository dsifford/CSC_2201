CC = g++
DEBUG = -g -Wextra
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

all: build

build: bootstrap ListLinked.o show5.o
	$(CC) $(LFLAGS) build/ListLinked.o build/show5.o test5.cpp -o $(BIN_PATH)/test5

ListLinked.o: ListLinked.cpp ListLinked.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

show5.o: show5.cpp ListLinked.h
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/show5.o show5.cpp

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -f $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test5