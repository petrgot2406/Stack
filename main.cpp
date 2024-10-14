#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

const uint64_t canary = 0xDED;

struct Stack_t
{
    uint64_t canary1;
    size_t capacity;
    size_t size;
    int* data;
    uint64_t canary2;
};

void PushStack(Stack_t* stk, int n);
void PopStack(Stack_t* stk);
int PeekStack(Stack_t stk);
void PrintStack(Stack_t stk);

int main()
{
    Stack_t stk = {};
    stk.canary1 = canary;
    stk.canary2 = canary;
    stk.capacity = 100;
    stk.size = 0;
    stk.data = (int*)calloc(stk.capacity, sizeof(int));

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

    free(stk.data);
    return 0;
}

void PushStack(Stack_t* stk, int n)
{
    assert(stk->size < stk->capacity);

    stk->data[stk->size] = n;
    stk->size++;
}

void PopStack(Stack_t* stk)
{
    assert(stk->size < stk->capacity);

    printf("I popped %d\n", stk->data[stk->size - 1]);
    stk->data[stk->size] = 0;
    stk->size--;
}

int PeekStack(Stack_t stk)
{
    assert(stk.size < stk.capacity);

    return stk.data[stk.size - 1];
}

void PrintStack(Stack_t stk)
{
    assert(stk.size < stk.capacity);

    for (size_t i = 0; i < stk.size; i++)
    {
        printf("%d\n", stk.data[i]);
    }
}