CC = g++
DEBUG = -g
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

OBJS = text.o textio.o test.o

all: build

build: bootstrap $(OBJS)
	$(CC) $(LFLAGS) $(BUILD_PATH)/* -o $(BIN_PATH)/test

text.o: Text.cpp
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/text.o Text.cpp

textio.o: textio.cpp
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/textio.o textio.cpp

test.o: test1.cpp
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/test.o test1.cpp

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -f $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test
