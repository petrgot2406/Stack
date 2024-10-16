#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "FuncStack.h"

void PushStack(Stack_t* stk, int n)
{
    assert(stk->params.size <= stk->params.capacity);

    if (stk->params.size + 1 > stk->params.capacity)
    {
        stk->stkdata.data = (int*)realloc(stk->stkdata.data,
                                          stk->params.capacity * sizeof(int) * 2);
        stk->params.capacity = stk->params.capacity * 2;
    }
    stk->stkdata.data[stk->params.size] = n;
    stk->params.size++;
}

int PopStack(Stack_t* stk)
{
    assert(stk->params.size <= stk->params.capacity);

    if (4 * (stk->params.size - 1) < stk->params.capacity)
    {
        stk->stkdata.data = (int*)realloc(stk->stkdata.data,
                                          stk->params.capacity * sizeof(int) / 2);
        stk->params.capacity = stk->params.capacity / 2;
    }
    printf("I popped %d\n", stk->stkdata.data[stk->params.size - 1]);
    int temp = stk->stkdata.data[stk->params.size];
    stk->stkdata.data[stk->params.size] = 0;
    stk->params.size--;
    return temp;
}

void InitStack(Stack_t* stk)
{
    stk->stkdata.canarystart = canary;
    stk->stkdata.canaryend = canary;
    stk->params.capacity = 8;
    stk->params.size = 0;
    stk->stkdata.data = (int*)calloc(stk->params.capacity, sizeof(int));
}

void DestroyStack(Stack_t* stk)
{
    stk->stkdata.canarystart = 0;
    stk->stkdata.canaryend = 0;
    stk->params.capacity = 0;
    stk->params.size = 0;
    free(stk->stkdata.data);
}

void DumpStack(Stack_t stk)
{
    printf("Capacity = %d\n", stk.params.capacity);
    printf("Size = %d\n", stk.params.size);
    printf("Data:\n");
    for (size_t i = 0; i < stk.params.size; i++)
    {
        printf("stack[%d] = %d\n", i, stk.stkdata.data[i]);
    }
}
