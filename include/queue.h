// Defining the structure for queue
typedef struct Queue
{
    int *items;
    int front, rear, size, capacity;
} Queue;

// Function declarations
Queue *create_queue(int capacity);
bool is_queue_empty(Queue *queue);
bool is_queue_full(Queue *queue);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
void free_queue(Queue *queue);
