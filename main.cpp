#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "Struct.h"
#include "InitDestroy.h"
#include "FuncStack.h"
#include "Output.h"

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
    PopStack(&stk);
    PushStack(&stk, 70);
    PushStack(&stk, 80);
    PushStack(&stk, 90);

    PrintStack(stk);

    DestroyStack(&stk);
    return 0;
}
