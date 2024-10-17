#ifndef STRUCT_H
#define STRUCT_H

#include <stdint.h>

#define CANARY 0xDEDDEDDEDDEDDEDF
#define BUFSIZE 8

struct Stack_t
{
    uint64_t canary_start;
    int* data;
    size_t capacity;
    size_t size;
    uint64_t canary_end;
};

#endif
