#ifndef FUNCSTACK_H
#define FUNCSTACK_H

#include "Struct.h"
#include "Constants.h"

error_t PushStack(Stack_t* stk, stackelem_t elem);
error_t PopStack(Stack_t* stk);
error_t InitStack(Stack_t* stk);
error_t DestroyStack(Stack_t* stk);
void DumpStack(Stack_t stk);

#endif
