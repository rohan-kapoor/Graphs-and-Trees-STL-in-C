#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "queue.h"

// Function to test queue creation
void test_queue_creation()
{
    int capacity = 5;
    Queue *queue = create_queue(capacity);

    assert(queue != NULL);
    assert(queue->capacity == capacity);
    assert(queue->size == 0);
    assert(queue->front == 0);
    assert(queue->rear == capacity - 1);

    free_queue(queue);

    printf("Queue creation test passed!\n");
}

// Function to test enqueue and dequeue operations
void test_queue_operations()
{
    int capacity = 5;
    Queue *queue = create_queue(capacity);

    assert(is_queue_empty(queue) == true);
    assert(is_queue_full(queue) == false);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    assert(is_queue_empty(queue) == false);
    assert(is_queue_full(queue) == false);

    assert(dequeue(queue) == 10);
    assert(dequeue(queue) == 20);

    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    assert(dequeue(queue) == 30);
    assert(dequeue(queue) == 40);
    assert(dequeue(queue) == 50);
    assert(dequeue(queue) == 60);

    assert(is_queue_empty(queue) == true);

    // Trying to dequeue from an empty queue
    assert(dequeue(queue) == -1);

    printf("Queue operations test passed!\n");

    free_queue(queue);
}

// Function to test queue overflow and underflow handling
void test_queue_overflow_underflow()
{
    int capacity = 3;
    Queue *queue = create_queue(capacity);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Queue is full now
    assert(is_queue_full(queue) == true);

    // Enqueue should show overflow message
    printf("Expected: Queue overflow\n");
    enqueue(queue, 4); // This should print "Queue overflow"

    assert(dequeue(queue) == 1);
    enqueue(queue, 4);

    // Queue should be full again
    assert(is_queue_full(queue) == true);

    // Dequeue all items
    assert(dequeue(queue) == 2);
    assert(dequeue(queue) == 3);
    assert(dequeue(queue) == 4);

    // Queue should be empty now
    assert(is_queue_empty(queue) == true);

    // Dequeue from an empty queue
    assert(dequeue(queue) == -1);

    printf("Queue overflow and underflow test passed!\n");

    free_queue(queue);
}

// Main function to run all tests
int main()
{
    test_queue_creation();
    test_queue_operations();
    test_queue_overflow_underflow();

    printf("All queue tests passed successfully!\n\n");

    return 0;
}
