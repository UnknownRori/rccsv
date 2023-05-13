CC = gcc
FLAG = -Wall -Werror
DEBUG = -g -DDEBUG -DCOLORED

TEMP = temp
DIST = dist
TEST = tests

RCCSV = rccsv
RCCSV_SRC = $(RCCSV).c
RCCSV_OUT = ./$(TEMP)/$(RCCSV).o
RCCSV_STATICLIB = ./$(DIST)/lib$(RCCSV).a
RCCSV_DLL = ./$(DIST)/$(RCCSV).dll # Maybe for next time

TEST_FLAG = -l$(RCCSV)
TEST_CASE = ./$(TEST)/unit_test.c
TEST_BIN = ./$(TEMP)/test

setup:
	([ ! -e ./$(DIST) ] && mkdir $(DIST)) || [ -e ./$(DIST) ]
	([ ! -e ./$(TEMP) ] && mkdir $(TEMP)) || [ -e ./$(TEMP) ]

clean: setup
	rm -r ./$(TEMP)
	rm -r ./$(DIST)

test: build-test
	$(TEST_BIN)

test-dll: build-test
	cp $(RCCSV_DLL) ./temp
	$(TEST_BIN)

build-test: setup build-dll
	$(CC) $(TEST_CASE) -o $(TEST_BIN) -L./$(DIST) $(TEST_FLAG) $(FLAG) $(DEBUG)

build-test-dll: setup build-dll
	$(CC) $(TEST_CASE) -o $(TEST_BIN) -L./$(DIST) $(TEST_FLAG) $(FLAG) $(DEBUG) -DDLL_IMPORT

build: build-static

build-static: setup build-obj
	ar rcs $(RCCSV_STATICLIB) $(RCCSV_OUT)

build-dll: setup build-obj
	gcc $(RCCSV_OUT) -o $(RCCSV_DLL) -s -shared

build-obj-dll: setup
	$(CC) $(RCCSV_SRC) -c -o $(RCCSV_OUT) $(FLAG) $(DEBUG) -DDLL_EXPORT

build-obj: setup
	$(CC) $(RCCSV_SRC) -c -o $(RCCSV_OUT) $(FLAG) $(DEBUG)