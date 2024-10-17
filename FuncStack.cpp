#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Constants.h"
#include "FuncStack.h"
#include "Struct.h"

error_t PushStack(Stack_t* stk, stackelem_t n)
{
    if (stk == NULL)
    {
        printf("ERROR IN ADDRESS OF STACK!\n");
        return ERROR_ADDRESS;
    }

    if (stk->size >= stk->capacity)
    {
        printf("ERROR IN SIZE OF STACK!\n");
        return ERROR_OVERFLOW;
    }

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
    return FOUND_OK;
}

error_t PopStack(Stack_t* stk)
{
    if (stk == NULL)
    {
        printf("ERROR IN ADDRESS OF STACK!\n");
        return ERROR_ADDRESS;
    }

    if (stk->size >= stk->capacity)
    {
        printf("ERROR IN SIZE OF STACK!\n");
        return ERROR_OVERFLOW;
    }

    if (4 * (stk->size - 2) < stk->capacity)
    {
        stk->data = (stackelem_t*)realloc(stk->data,
                                          stk->capacity * sizeof(stackelem_t) / 2);
        stk->capacity = stk->capacity / 2;
    }
    printf("pop\n");
    stk->data[stk->size] = 0;
    stk->size--;
    DumpStack(*stk);
    return FOUND_OK;
}

error_t InitStack(Stack_t* stk)
{
    if (stk == NULL) {
        printf("ERROR IN ADDRESS OF STACK!\n");
        return ERROR_ADDRESS;
    }

    stk->canary_start = canary;
    stk->canary_end = canary;
    stk->capacity = 8;
    stk->size = 0;
    stk->data = (int*)calloc(stk->capacity, sizeof(stackelem_t));
    return FOUND_OK;
}

error_t DestroyStack(Stack_t* stk)
{
    if (stk == NULL) {
        printf("ERROR IN ADDRESS OF STACK!\n");
        return ERROR_ADDRESS;
    }

    stk->canary_start = 0;
    stk->canary_end = 0;
    stk->capacity = 0;
    stk->size = 0;
    free(stk->data);
    return FOUND_OK;
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
