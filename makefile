CC = gcc
FLAG = -Wall -Werror -Wconversion -Wundef -Wshadow -Wdouble-promotion -fno-common -Wformat=2
DEBUG = -g -DDEBUG -DCOLORED -fstack-usage

TEMP = temp
DIST = dist
TEST = tests
SRC  = src

RCCSV = rccsv
RCCSV_SRC = $(RCCSV).c
RCCSV_OUT = ./$(TEMP)/$(RCCSV).o
RCCSV_STATICLIB = ./$(DIST)/lib$(RCCSV).a
RCCSV_DLL = ./$(DIST)/$(RCCSV).dll # Maybe for next time

WRAPPER_SRC = ./$(SRC)/FILE.c
WRAPPER_OUT = ./$(TEMP)/wrapper.o

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

test-dll: build-test-dll
	cp $(RCCSV_DLL) ./temp
	$(TEST_BIN)

build-test: setup build-static
	$(CC) $(TEST_CASE) -o $(TEST_BIN) -L./$(DIST) $(TEST_FLAG) $(FLAG) $(DEBUG)

build-test-dll: setup build-dll
	$(CC) $(TEST_CASE) -o $(TEST_BIN) -L./$(DIST) $(TEST_FLAG) $(FLAG) $(DEBUG) -DDLL_IMPORT

build: build-static

build-static: setup build-obj build-wrapper-obj
	ar rcs $(RCCSV_STATICLIB) $(RCCSV_OUT) $(WRAPPER_OUT)

build-dll: setup build-obj build-wrapper-obj
	gcc $(RCCSV_OUT) $(WRAPPER_OUT) -o $(RCCSV_DLL) -s -shared

build-obj-dll: setup
	$(CC) $(RCCSV_SRC) -c -o $(RCCSV_OUT) $(FLAG) $(DEBUG) -DDLL_EXPORT

build-obj: setup
	$(CC) $(RCCSV_SRC) -c -o $(RCCSV_OUT) $(FLAG) $(DEBUG)

build-wrapper-obj: setup
	$(CC) $(WRAPPER_SRC) -c -o $(WRAPPER_OUT) $(FLAG) $(DEBUG)