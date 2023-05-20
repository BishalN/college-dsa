#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Initialize an empty stack
struct Node *top = NULL;

// Check if the stack is empty
int isEmpty()
{
    return top == NULL;
}

// Push an element onto the stack
void push(int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;

    // Set the new node as the top of the stack
    top = newNode;

    printf("%d pushed to the stack.\n", value);
}

// Pop an element from the stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return -1;
    }

    // Store the value of the top node
    int poppedValue = top->data;

    // Move the top to the next node
    struct Node *temp = top;
    top = top->next;

    // Free the memory of the previous top node
    free(temp);

    return poppedValue;
}

// Get the top element of the stack without removing it
int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return -1;
    }

    return top->data;
}

// Display the elements in the stack
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Elements in the stack: ");
    struct Node *current = top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    display(); // Output: Elements in the stack: 30 20 10

    printf("Top element: %d\n", peek()); // Output: Top element: 30

    printf("Popped element: %d\n", pop()); // Output: Popped element: 30

    display(); // Output: Elements in the stack: 20 10

    return 0;
}
