#ifndef FUNCSTACK_H
#define FUNCSTACK_H

#include "Struct.h"
#include "Constants.h"

Error_t PushStack(Stack_t* stk, stackelem_t elem);
Error_t PopStack(Stack_t* stk);
Error_t InitStack(Stack_t* stk);
Error_t DestroyStack(Stack_t* stk);
Error_t DumpStack(Stack_t stk);

#endif
