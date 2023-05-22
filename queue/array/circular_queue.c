// makeEmpty, isEmpty, isfull, Enqueue, Dequeue, front, rear, printQueue

#include<stdio.h>

#define MAXQUEUESIZE 5

struct CircularQueue {
    int arr[MAXQUEUESIZE];
    int front;
    int rear;
};

typedef struct CircularQueue CQ;

// Initialize the queue
void makeEmpty(CQ *cq)
{
    cq->front = MAXQUEUESIZE - 1;
    cq->rear = MAXQUEUESIZE - 1;
}

int isEmpty(CQ *cq) {
    if(cq->rear == cq->front)
        return 1;
    return 0;
}

int isFull(CQ *cq) {
    // IN CQ there is always one space empty and difference between front and rear
    // position is just one when CQ is full so
    if(cq->front == ((cq->rear + 1) % MAXQUEUESIZE))
        return 1;
    return 0;
}

void enqueue(CQ *cq, int item) {
    // check if the queue is full first
    if(isFull(cq)) {
        printf("Queue overlflow \n");
        return;
    }
    // rear is used to enqueue so
    cq->rear = (cq->rear + 1) % MAXQUEUESIZE;
    cq->arr[cq->rear] = item;
}

int dequeue(CQ *cq) {
    // check if the queue is empty first
    if(isEmpty(cq)) {
        printf("Queue run \n");
        return -1;
    }

    // front is used to dequeue so
    cq->front = (cq->front + 1) % MAXQUEUESIZE;
    int dequeued_item = cq->arr[cq->front];
    return dequeued_item;
}

void display_queue(CQ *cq) {
    // we start from the front and go the end 
    // TODO: we need to make a copy of the queue here
    // or we could just use the size variable as well in queue
    while(!isEmpty(cq)) {
        int item = dequeue(cq);
        printf("%d \n", item);
    }
}

int main() {
    CQ cq;
    makeEmpty(&cq);
    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    enqueue(&cq, 4);
    enqueue(&cq, 4);
    enqueue(&cq, 4);

    display_queue(&cq);
    display_queue(&cq);

    return 0;
}