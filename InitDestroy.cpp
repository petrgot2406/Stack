#include <stdlib.h>
#include <stdint.h>
#include "Struct.h"
#include "InitDestroy.h"

void InitStack(Stack_t* stk)
{
    stk->canary1 = canary;
    stk->canary2 = canary;
    stk->capacity = 100;
    stk->size = 0;
    stk->data = (int*)calloc(stk->capacity, sizeof(int));
}

void DestroyStack(Stack_t* stk)
{
    stk->canary1 = 0;
    stk->canary2 = 0;
    stk->capacity = 0;
    stk->size = 0;
    free(stk->data);
}
