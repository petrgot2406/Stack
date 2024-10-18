#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"
#include "FuncStack.h"
#include "Struct.h"

Error_t PushStack(Stack_t* stk, stackelem_t new_elem)
{
    Error_t stack_error = CheckStack(*stk);

    if (stack_error != FOUND_OK)
    {
        return stack_error;
    }

    if (stk->size + 2 > stk->capacity)
    {
        stk->capacity *= 2;
        ReallocData(stk);
    }

    printf("push %d\n", new_elem);

    *((stackelem_t*)(stk->data + 1) + stk->size) = new_elem;
    stk->size++;

    DumpStack(*stk);

    return stack_error;
}

Error_t PopStack(Stack_t* stk)
{
    Error_t stack_error = CheckStack(*stk);

    if (stack_error != FOUND_OK)
    {
        return stack_error;
    }

    if (4 * (stk->size - 2) < stk->capacity)
    {
        stk->capacity /= 2;
        ReallocData(stk);
    }

    printf("pop\n");

    *((stackelem_t*)(stk->data + 1) + stk->size) = 0;
    stk->size--;

    DumpStack(*stk);

    return stack_error;
}

Error_t InitStack(Stack_t* stk)
{
    if (stk == NULL)
    {
        printf("ERROR IN ADDRESS OF STACK!\n");
        return ERROR_ADDRESS;
    }

    stk->canary_start = canary;
    stk->canary_end = canary;

    stk->capacity = 8;
    stk->size = 0;

    stk->data = (canary_type*)calloc(sizeof(canary_type) * 2 +
                                         stk->capacity * sizeof(stackelem_t), 1);
    stk->data[0] = canary;
    *((canary_type*)((char*)stk->data + sizeof(canary_type) +
                      stk->capacity * sizeof(stackelem_t))) = canary;

    return FOUND_OK;
}

Error_t DestroyStack(Stack_t* stk)
{
    Error_t stack_error = CheckStack(*stk);

    if (stack_error != FOUND_OK)
    {
        return stack_error;
    }

    free(stk->data);
    free(stk);

    return stack_error;
}

Error_t DumpStack(Stack_t stk)
{
    Error_t stack_error = CheckStack(stk);

    if (stack_error != FOUND_OK)
    {
        return stack_error;
    }

    printf("dump\n");
    printf("Capacity = %d\n", stk.capacity);
    printf("Size = %d\n", stk.size);
    printf("Data:\n");

    for (size_t i = 0; i < stk.size; i++)
    {
        printf_elem(i, *((stackelem_t*)(stk.data + 1) + i));
    }

    printf("\n");

    return stack_error;
}

Error_t CheckStack(Stack_t stk)
{
    if (stk.size >= stk.capacity)
    {
        printf("ERROR IN SIZE OF STACK!\n");
        return ERROR_OVERFLOW;
    }

    if (stk.data == NULL)
    {
        printf("ERROR IN DATA!\n");
        return ERROR_DATA;
    }

    if (stk.canary_start != canary || stk.canary_end != canary)
    {
        printf("ERROR IN CANARY STACK!\n");
        return ERROR_CANARY_STACK;
    }

    if (stk.data[0] != canary ||
        *((canary_type*)((char*)stk.data + sizeof(canary_type) +
                          stk.capacity * sizeof(stackelem_t))) != canary)
    {
        printf("ERROR IN CANARY DATA!\n");
        return ERROR_CANARY_DATA;
    }

    return FOUND_OK;
}

Error_t ReallocData(Stack_t* stk)
{
    stk->data = (canary_type*)realloc(stk->data, sizeof(canary_type) * 2 +
                                      stk->capacity * sizeof(stackelem_t));

    stk->data[0] = canary;
    *((canary_type*)((char*)stk->data + sizeof(canary_type) +
                      stk->capacity * sizeof(stackelem_t))) = canary;

    Error_t stack_error = CheckStack(*stk);

    if (stack_error != FOUND_OK)
    {
        return stack_error;
    }

    return stack_error;
}
