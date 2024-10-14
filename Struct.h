#ifndef STRUCT_H
#define STRUCT_H

#include <stdint.h>

const uint64_t canary = 0xDEDDEDDEDDEDDEDF;


struct Stack_parameters
{
    size_t capacity;
    size_t size;
};

struct Stack_data
{
    uint64_t canarystart;
    int* data;
    uint64_t canaryend;
};

struct Stack_t
{
    struct Stack_parameters params;
    struct Stack_data stkdata;
};

#endif
