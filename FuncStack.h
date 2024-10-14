#ifndef FUNCSTACK_H
#define FUNCSTACK_H

#include "Struct.h"

void PushStack(Stack_t* stk, int n);
int PopStack(Stack_t* stk);
void InitStack(Stack_t* stk);
void DestroyStack(Stack_t* stk);
void DumpStack(Stack_t stk);

#endif
