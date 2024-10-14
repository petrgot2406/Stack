#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "FuncStack.h"

void InitStack(Stack_t* stk)
{
    stk->canarystart = canary;
    stk->canaryend = canary;
    stk->capacity = 8;
    stk->size = 0;
    stk->data = (int*)calloc(stk->capacity, sizeof(int));
}

void DestroyStack(Stack_t* stk)
{
    stk->canarystart = 0;
    stk->canaryend = 0;
    stk->capacity = 0;
    stk->size = 0;
    free(stk->data);
}

void PushStack(Stack_t* stk, int n)
{
    if (stk->size + 1 > stk->capacity)
    {
        stk->data = (int*)realloc(stk->data, 2 * stk->size * sizeof(int));
    }
    stk->data[stk->size] = n;
    stk->size++;
}

int PopStack(Stack_t* stk)
{
    if (4 * (stk->size - 1) < stk->capacity)
    {
        stk->data = (int*)realloc(stk->data, stk->size * sizeof(int) / 2);
    }
    printf("I popped %d\n", stk->data[stk->size - 1]);
    int temp = stk->data[stk->size];
    stk->data[stk->size] = 0;
    stk->size--;
    return temp;
}

void DumpStack(Stack_t stk)
{
    assert(stk.size <= stk.capacity);

    for (size_t i = 0; i < stk.size; i++)
    {
        printf("%d\n", stk.data[i]);
    }
}
