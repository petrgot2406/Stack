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
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);
    PopStack(&stack);

    DestroyStack(&stack);

    return 0;
}
