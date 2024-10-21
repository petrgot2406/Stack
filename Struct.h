#ifndef STRUCT_H
#define STRUCT_H

#include "Constants.h"

struct HashStruct
{
    unsigned long hash_stack;
    unsigned long hash_data;
};

struct Stack_t
{
    canary_type canary_start;
    canary_type* data;
    size_t capacity;
    size_t size;
    HashStruct hash_struct;
    canary_type canary_end;
};

#endif
