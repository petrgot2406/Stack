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
    PushStack(&stk, 90);
    PushStack(&stk, 100);
    PushStack(&stk, 110);
    PushStack(&stk, 120);
    PushStack(&stk, 130);
    PushStack(&stk, 140);
    PushStack(&stk, 150);
    PushStack(&stk, 160);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
    PopStack(&stk);
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
