#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>

#define printf_elem(number, element) printf("stack[%d] = %d\n", number, element)

typedef long long int canary_type;
typedef int stackelem_t;

const canary_type canary = 0xDEDDEDDEDDEDDEDF;

enum Error_t
{
    FOUND_OK = 0,
    ERROR_ADDRESS = 1,
    ERROR_OVERFLOW = 2,
    ERROR_DATA = 3,
    ERROR_CANARY_STACK = 4,
    ERROR_CANARY_DATA = 5,
    ERROR_HASH_ADDRESS = 6,
    ERROR_HASH_STACK = 7,
    ERROR_HASH_DATA = 8
};

#endif
