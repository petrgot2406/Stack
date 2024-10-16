#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "Struct.h"
#include "FuncStack.h"

int main()
{
    Stack_t stk = {};

    InitStack(&stk);

    PushStack(&stk, 10);
    PushStack(&stk, 20);
    PushStack(&stk, 30);
    PushStack(&stk, 40);
    PushStack(&stk, 50);
    PushStack(&stk, 60);
    PushStack(&stk, 60);
    PushStack(&stk, 70);
    PushStack(&stk, 80);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);

    DestroyStack(&stk);

    return 0;
}
