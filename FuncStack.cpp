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

    stk->hash_struct.hash_stack = Hash((char*)stk,
                                       sizeof(canary_type*) +
                                       2 * sizeof(size_t));
    stk->hash_struct.hash_data = Hash((char*)stk->data,
                                      2 * sizeof(canary_type) +
                                      stk->capacity * sizeof(stackelem_t));

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

    stk->hash_struct.hash_stack = Hash((char*)stk,
                                       sizeof(canary_type*) +
                                       2 * sizeof(size_t));
    stk->hash_struct.hash_data = Hash((char*)stk->data,
                                      2 * sizeof(canary_type) +
                                      stk->capacity * sizeof(stackelem_t));

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

    stk->hash_struct.hash_stack = Hash((char*)stk,
                                       sizeof(canary_type*) +
                                       2 * sizeof(size_t));
    stk->hash_struct.hash_data = Hash((char*)stk->data,
                                      2 * sizeof(canary_type) +
                                      stk->capacity * sizeof(stackelem_t));

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
    stk->capacity = 0;
    stk->size = 0;
    stk->hash_struct.hash_stack = 0;
    stk->hash_struct.hash_data = 0;

    return FOUND_OK;
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

    if (Hash((char*)stk.data, 2 * sizeof(canary_type) +
                    stk.capacity * sizeof(stackelem_t)) !=
                    stk.hash_struct.hash_data)
    {
        printf("ERROR IN HASH DATA!\n");
        return ERROR_HASH_DATA;
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

unsigned long Hash(char* data, size_t size)
{
    unsigned long hash = 1234;
    char* str = data;
    char c = 0;

    for (size_t i = 0; i < size; i++)
    {
        c = str[i];
        hash = ~(hash << 3) ^ c;
    }

    return hash;
}
