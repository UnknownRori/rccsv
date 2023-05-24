#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./test_framework.h"

#include "../src/FILE.h"

TEST_CASE(read_entire_line);

int main(int argc, char **argv)
{
    TEST_CASE_REGISTER(read_entire_line);

    return 0;
}

TEST_CASE(read_entire_line)
{
    TEST_CASE_INIT()

    FILE *fp = fopen("./tests/data/dummy.txt", "r");

    TEST_CASE_EXPECT(fp != nullptr, "It should open the file");

    char *result = readline(fp);

    TEST_CASE_EXPECT(strcmp(result, "AAAA") == 0, "It should be the same thing");

    free(result);

    TEST_CASE_DONE()
}