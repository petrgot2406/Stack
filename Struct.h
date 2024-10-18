#ifndef STRUCT_H
#define STRUCT_H

#include "Constants.h"

struct Stack_t
{
    canary_type canary_start;
    canary_type* data;
    stackelem_t* array;
    size_t capacity;
    size_t size;
    canary_type canary_end;
};

#endif
