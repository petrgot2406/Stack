#include <stdio.h>
#include <assert.h>
#include "Struct.h"
#include "Output.h"

void PrintStack(Stack_t stk)
{
    assert(stk.size < stk.capacity);

    for (size_t i = 0; i < stk.size; i++)
    {
        printf("%d\n", stk.data[i]);
    }
}
