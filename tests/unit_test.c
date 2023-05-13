#include "./assert.h"

extern int hello();

int main()
{
    ASSERT(hello() == 1, "It should be one");

    return 0;
}