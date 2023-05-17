#include "./assert.h"

extern int hello();

int main()
{
    ASSERT(hello() == 4, "It should be four");

    return 0;
}