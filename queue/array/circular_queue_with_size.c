#include <stdio.h>

#define MAX_SIZE 5

struct CircularQueue {
    int array[MAX_SIZE];
    int front;
    int rear;
    int size;
};

// Function to create a new circular queue
void createCircularQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->size == 0);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Circular queue is full. Enqueue operation failed.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = data;
    queue->size++;

    printf("%d enqueued to the circular queue.\n", data);
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int data = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;

    if (isEmpty(queue)) {
        queue->front = -1;
        queue->rear = -1;
    }

    return data;
}

// Function to display the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular queue: ");
    int i;
    for (i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % MAX_SIZE;
        printf("%d ", queue->array[index]);
    }
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    createCircularQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);  // Queue is full, will fail

    display(&queue);

    int dequeuedElement = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeuedElement);

    enqueue(&queue, 60);

    display(&queue);

    return 0;
}
