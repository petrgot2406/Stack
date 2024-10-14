#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "Struct.h"
#include "FuncStack.h"

void PushStack(Stack_t* stk, int n)
{
    assert(stk->size < stk->capacity);

    stk->data[stk->size] = n;
    stk->size++;
}

void PopStack(Stack_t* stk)
{
    assert(stk->size < stk->capacity);

    printf("I popped %d\n", stk->data[stk->size - 1]);
    stk->data[stk->size] = 0;
    stk->size--;
}

int PeekStack(Stack_t stk)
{
    assert(stk.size < stk.capacity);

    return stk.data[stk.size - 1];
}
