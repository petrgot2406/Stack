#ifndef STRUCT_H
#define STRUCT_H

#include <stdint.h>

const uint64_t canary = 0xDEDDEDDEDDEDDEDF;

struct Stack_t
{
    uint64_t canarystart;
    size_t capacity;
    size_t size;
    int* data;
    uint64_t canaryend;
};

#endif
