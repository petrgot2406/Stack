#ifndef FUNCSTACK_H
#define FUNCSTACK_H

#include "Struct.h"
#include "Constants.h"

stackelem_t PushStack(Stack_t* stk, stackelem_t n);
stackelem_t PopStack(Stack_t* stk);
void InitStack(Stack_t* stk);
void DestroyStack(Stack_t* stk);
void DumpStack(Stack_t stk);

#endif
