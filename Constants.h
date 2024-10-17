#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>

#define printf_elem(number, element) printf("stack[%d] = %d\n", number, element)

typedef long long int canary_type;
const canary_type canary = 0xDEDDEDDEDDEDDEDF;

#endif
