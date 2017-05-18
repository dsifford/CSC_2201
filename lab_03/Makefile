CC = g++
DEBUG = -g
LFLAGS = -Wall -std=c++11 $(DEBUG)
CFLAGS = -c $(LFLAGS)

BUILD_PATH = build
BIN_PATH = bin
# $(CC) $(LFLAGS) sumintegers.cpp -o $(BIN_PATH)/sumintegers
# $(CC) $(LFLAGS) test3dna.cpp -o $(BIN_PATH)/test3dna

all: build

build: bootstrap ListArray.o show3.o
	$(CC) $(LFLAGS) build/ListArray.o build/show3.o test3.cpp -o $(BIN_PATH)/test3

ListArray.o: ListArray.cpp ListArray.h
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/ListArray.o ListArray.cpp

show3.o: show3.cpp ListArray.h
	$(CC) $(CFLAGS) -o $(BUILD_PATH)/show3.o show3.cpp

.PHONY: bootstrap
bootstrap:
	@mkdir -p ./{$(BUILD_PATH),$(BIN_PATH)}

.PHONY: clean
clean:
	@rm -f $(BUILD_PATH)/* $(BIN_PATH)/*

.PHONY: run
run:
	@ ./bin/test3
