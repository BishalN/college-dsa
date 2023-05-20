#include <stdio.h>
#include "stack.h"

void initializeStack(Stack *st)
{
    st->top = -1;
}

int isEmpty(Stack *st)
{
    if (st->top == -1)
        return 1;
    return 0;
}

int isFull(Stack *st)
{
    if (st->top == MAXSIZE - 1)
        return 1;
    return 0;
}

void push(Stack *st, int item)
{
    if (isFull(st))
    {
        printf("Stack overflow \n");
    }
    else
    {

        // increment the top
        st->top = st->top + 1;
        // push the item
        st->items[st->top] = item;
    }
}

int pop(Stack *st)
{
    // TODO: check if the stack is empty
    if (isEmpty(st))
    {
        printf("Stack Undeflow \n");
        return -1;
    }
    else
    {

        //  get the last element
        int popped_item = st->items[st->top];
        // decrement the top
        st->top = st->top - 1;
        // return the popped item
        return popped_item;
    }
}

void traverseStack(Stack *st)
{
    printf("Total Elements: %d \n", st->top + 1);
    for (int i = 0; i <= st->top; i++)
    {
        printf("Item at position %d: %d \n", i + 1, st->items[st->top - i]);
    }
}

// int main()
// {
//     Stack st = create();

//     pop(&st);

//     for (int i = 0; i < 105; i++)
//     {
//         push(&st, i);
//     }

//     push(&st, 1);
//     push(&st, 2);
//     push(&st, 3);

//     int value = pop(&st);
//     printf("Popped value is %d \n", value);

//     traverseStack(&st);
// }