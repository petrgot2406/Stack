#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Constants.h"
#include "FuncStack.h"
#include "Struct.h"

int PushStack(Stack_t* stk, stackelem_t n)
{
    assert(stk->size < stk->capacity);

    if (stk->size + 2 > stk->capacity)
    {
        stk->data = (stackelem_t*)realloc(stk->data,
                                          stk->capacity * sizeof(stackelem_t) * 2);
        stk->capacity = stk->capacity * 2;
    }
    printf("push %d\n", n);
    stk->data[stk->size] = n;
    stk->size++;
    DumpStack(*stk);
    return n;
}

int PopStack(Stack_t* stk)
{
    assert(stk->size < stk->capacity);

    if (4 * (stk->size - 2)< stk->capacity)
    {
        stk->data = (stackelem_t*)realloc(stk->data,
                                          stk->capacity * sizeof(stackelem_t) / 2);
        stk->capacity = stk->capacity / 2;
    }
    printf("pop\n");
    stackelem_t temp = stk->data[stk->size];
    stk->data[stk->size] = 0;
    stk->size--;
    DumpStack(*stk);
    return temp;
}

void InitStack(Stack_t* stk)
{
    stk->canary_start = canary;
    stk->canary_end = canary;
    stk->capacity = 8;
    stk->size = 0;
    stk->data = (int*)calloc(stk->capacity, sizeof(stackelem_t));
}

void DestroyStack(Stack_t* stk)
{
    stk->canary_start = 0;
    stk->canary_end = 0;
    stk->capacity = 0;
    stk->size = 0;
    free(stk->data);
}

void DumpStack(Stack_t stk)
{
    printf("dump\n");
    printf("Capacity = %d\n", stk.capacity);
    printf("Size = %d\n", stk.size);
    printf("Data:\n");
    for (size_t i = 0; i < stk.size; i++)
    {
        printf_elem(i, stk.data[i]);
    }
    printf("\n");
}
