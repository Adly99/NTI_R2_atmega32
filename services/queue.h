
void creatEmptyQueue(ST_queue_t *queue);
int isFull(ST_queue_t *queue);
int isEmpty(ST_queue_t *queue);
int enqueue(ST_queue_t *queue,int data);
int dequeue(ST_queue_t *queue,int *data);
int printQueue(ST_queue_t *queue);
int getQueueFront(ST_queue_t *queue);
int getQueueRear(ST_queue_t *queue);