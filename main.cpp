#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "Struct.h"
#include "StackFunc.h"
#include "StackUtils.h"
#include "StackHash.h"

int main()
{
    Stack_t stack = {};

    InitStack(&stack);

    PushStack(&stack, 10);
    PushStack(&stack, 20);
    PushStack(&stack, 30);
    PushStack(&stack, 40);
    PushStack(&stack, 50);
    PushStack(&stack, 60);
    PushStack(&stack, 70);
    PushStack(&stack, 80);
    PushStack(&stack, 90);
    PushStack(&stack, 100);
    PushStack(&stack, 110);
    PushStack(&stack, 120);
    PushStack(&stack, 130);
    PushStack(&stack, 140);
    PushStack(&stack, 150);
    PushStack(&stack, 160);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);

    DestroyStack(&stack);

    return 0;
}
