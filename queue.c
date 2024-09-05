#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

// To create a queue of given capacity
Queue* create_queue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->items = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// To check if the queue is empty
bool is_queue_empty(Queue* queue) {
    return (queue->size == 0);
}

// To check if the queue is full
bool is_queue_full(Queue* queue) {
    return (queue->size == queue->capacity);
}

// To add an item to the queue
void enqueue(Queue* queue, int item) {
    if (is_queue_full(queue)) {
        printf("Queue overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->size++;
}

// To remove an item from the queue
int dequeue(Queue* queue) {
    if (is_queue_empty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// To free the queue memory
void free_queue(Queue* queue){
    free(queue->items);
    free(queue);
}