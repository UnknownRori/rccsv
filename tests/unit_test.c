#include "./assert.h"

extern int hello();

int main()
{
    ASSERT(hello() == 1, "It should be one");
    ASSERT(hello() == 4, "It should be four");

    return 0;
}