#define MAXSIZE 100

struct St
{
    int items[MAXSIZE];
    int top;
};

typedef struct St Stack;

void initializeStack(Stack *st);
void push(Stack *st, int item);
int pop(Stack *st);
void traverseStack(Stack *st);
int isEmpty(Stack *st);
int isFull(Stack *st);