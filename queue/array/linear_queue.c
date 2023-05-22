// the functions for the queues are
// makeEmpty, isEmpty, isfull, Enqueue, Dequeue, front, rear, printQueue

#include<stdio.h>

#define MAXQUEUESIZE 50

struct Queue {
    int arr[MAXQUEUESIZE];
    int front;
    int rear;
};

typedef struct Queue Q;

void makeEmpty(Q *qu) {
    qu->front = 0;
    qu->rear = -1;
}

int isEmpty(Q *qu) {
    // if rear is smaller than front then queue is empty
    if(qu->rear < qu->front)
        return 1;
    return 0;
}

int isFull(Q *qu) {
    // if rear is equal to maxsize - 1 then queue is full
    if(qu->rear == MAXQUEUESIZE - 1)
        return 1;
    return 0;
}

void enqueue(Q *qu, int item) {
    if(isFull(qu)) {
        printf("Queue overflow\n");
        return;
    }
    // insert item at rear
    qu->rear = qu->rear + 1;
    qu->arr[qu->rear] = item;
}

int dequeue(Q *qu) {
    if(isEmpty(qu)) {
        printf("Queue run\n");
        return -1;
    }
    // remove the item from front
    int dequeued_item = qu->arr[qu->front];
    qu->front = qu->front + 1;
    return dequeued_item;
}

void print_queue(Q *qu) {
    // go up to the rear and start from front
    printf("****************Traversing through a queue****************\n");
    for (int i = qu->front; i <= qu->rear; i++)
    {
        printf(" %d \n", qu->arr[i]);
    }
}

int main() {
    Q qu;
    makeEmpty(&qu);
    enqueue(&qu, 1);
    enqueue(&qu, 2);
    enqueue(&qu, 3);
    enqueue(&qu, 4);
    enqueue(&qu, 5);
    dequeue(&qu);
    dequeue(&qu);
    dequeue(&qu);
    dequeue(&qu);
    dequeue(&qu);
    dequeue(&qu);
    dequeue(&qu);
    dequeue(&qu);
    print_queue(&qu);
    return 0;
}