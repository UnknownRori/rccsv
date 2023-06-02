#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./test_framework.h"

#include "../include/UnknownRori/rccsv.h"
#include "../src/FILE.h"

#define TEST_DIR_APPEND(_PATH) "./tests/data/" _PATH

TEST_CASE(read_entire_line);
TEST_CASE(load_header_csv_1);

int main(int argc, char **argv)
{
    TEST_CASE_REGISTER(read_entire_line);
    TEST_CASE_REGISTER(load_header_csv_1);

    return 0;
}

TEST_CASE(read_entire_line)
{
    TEST_CASE_INIT()

    FILE *fp = fopen(TEST_DIR_APPEND("dummy.txt"), "r");

    TEST_CASE_EXPECT(fp != nullptr, "It should open the file");

    char *result = readline(fp);

    TEST_CASE_EXPECT(strcmp(result, "AAAA") == 0, "It should be the same thing");

    free(result);

    TEST_CASE_DONE()
}

TEST_CASE(load_header_csv_1)
{
    TEST_CASE_INIT();

    const char *expected = "Id,Name,Birth Year";

    rccsv *fd = rccsv_open(TEST_DIR_APPEND("first.csv"));

    TEST_CASE_EXPECT(fd != nullptr, "It should open the file");

    const char *result_header = rccsv_headers(fd);

    TEST_CASE_EXPECT(strcmp(expected, result_header) == 0, "it should be the same thing");

    TEST_CASE_DONE();
}