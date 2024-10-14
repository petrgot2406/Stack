#ifndef STRUCT_H
#define STRUCT_H

#include <stdint.h>

const uint64_t canary = 0xDED;

struct Stack_t
{
    uint64_t canary1;
    size_t capacity;
    size_t size;
    int* data;
    uint64_t canary2;
};

#endif
