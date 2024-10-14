#include <stdlib.h>
#include <stdint.h>
#include "Struct.h"
#include "InitDestroy.h"

void InitStack(Stack_t* stk)
{
    stk->canarystart = canary;
    stk->canaryend = canary;
    stk->capacity = 100;
    stk->size = 0;
    stk->data = (int*)calloc(stk->capacity, sizeof(int));
}

void DestroyStack(Stack_t* stk)
{
    stk->canarystart = 0;
    stk->canaryend = 0;
    stk->capacity = 0;
    stk->size = 0;
    free(stk->data);
}
