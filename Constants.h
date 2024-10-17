#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>

#define printf_elem(number, element) printf("stack[%d] = %d\n", number, element)

typedef long long int canary_type;
typedef int stackelem_t;
const canary_type canary = 0xDEDDEDDEDDEDDEDF;

enum error_t
{
    FOUND_OK = 0,
    ERROR_ADDRESS = 1,
    ERROR_OVERFLOW = 2
};

#endif
