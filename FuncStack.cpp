#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "FuncStack.h"

int PushStack(Stack_t* stk, int n)
{
    assert(stk->size <= stk->capacity);

    if (stk->size + 2 > stk->capacity)
    {
        stk->data = (int*)realloc(stk->data,
                                  stk->capacity * sizeof(int) * 2);
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
    assert(stk->size <= stk->capacity);

    if (4 * (stk->size - 2)< stk->capacity)
    {
        stk->data = (int*)realloc(stk->data,
                                  stk->capacity * sizeof(int) / 2);
        stk->capacity = stk->capacity / 2;
    }
    printf("pop\n");
    int temp = stk->data[stk->size];
    stk->data[stk->size] = 0;
    stk->size--;
    DumpStack(*stk);
    return temp;
}

void InitStack(Stack_t* stk)
{
    stk->canary_start = CANARY;
    stk->canary_end = CANARY;
    stk->capacity = BUFSIZE;
    stk->size = 0;
    stk->data = (int*)calloc(stk->capacity, sizeof(int));
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
        printf("stack[%d] = %d\n", i, stk.data[i]);
    }
    printf("\n");
}
