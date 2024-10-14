#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "FuncStack.h"

void PushStack(Stack_t* stk, int n)
{
    if (stk->size + 1 > stk->capacity)
    {
        stk->data = (int*)realloc(stk->data, 2 * stk->size * sizeof(int));
    }
    stk->data[stk->size] = n;
    stk->size++;
}

void PopStack(Stack_t* stk)
{
    if (4 * (stk->size - 1) < stk->capacity)
    {
        stk->data = (int*)realloc(stk->data, stk->size * sizeof(int) / 2);
    }
    printf("I popped %d\n", stk->data[stk->size - 1]);
    stk->data[stk->size] = 0;
    stk->size--;
}

int PeekStack(Stack_t stk)
{
    return stk.data[stk.size - 1];
}
