#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    // 1. for push, 2. for pop, 3. for display, 4. for exit
    int choice;
    Stack st;
    initializeStack(&st);
    printf("********* Stack Demo Menu ********* \n");
    do
    {
        printf("\n Press 1 for pushing \n Press 2 for popping \n press 3 to display \n press 4 to exit \n\n");
        scanf("\t\t %d", &choice);
        switch (choice)
        {
        case 1:
        {
            int item = 0;
            printf("\n Please enter the value: ");
            scanf("\t\t %d", &item);
            push(&st, item);
            break;
        }
        case 2:
        {
            int popped_item = pop(&st);
            printf("\n Popped Item: %d \n\n", popped_item);
            break;
        }
        case 3:
            printf("*************Traversing Stack************* \n\n");
            traverseStack(&st);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Option");
        }
    } while (choice != 4);
}