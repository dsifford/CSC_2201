CC = g++
DEBUG = -g -Wextra
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin

all: build

build: bootstrap QueueArray.o QueueLinked.o 
	$(CC) $(LFLAGS) build/QueueArray.o build/QueueLinked.o test7.cpp -o $(BIN_PATH)/test7

QueueArray.o: QueueArray.cpp QueueArray.h Queue.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

QueueLinked.o: QueueLinked.cpp QueueLinked.h Queue.h
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

show7.o: Queue.h QueueLinked.h QueueArray.h show7.cpp
	$(CC) $(CFLAGS) $*.cpp -o $(BUILD_PATH)/$@

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -f $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test7