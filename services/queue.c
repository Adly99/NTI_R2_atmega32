#include <stdio.h>
#include <stdlib.h>

# define QUEUE_SIZE 10

typedef struct queue
{
    int element[QUEUE_SIZE];
    int front;
    int rear;
}ST_queue_t;

void creatEmptyQueue(ST_queue_t *queue)
{
    queue ->front = -1;
    queue ->rear = -1;
}

int isFull(ST_queue_t *queue)
{
    if (queue->rear == QUEUE_SIZE-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    
}

int isEmpty(ST_queue_t *queue)
{   
    if (queue->front == -1 && queue->rear = -1)
    {
        return 1;           //True
    }
    else
    {
        return 0;       //False
    }
}
/*		
        adding at the rear of the queue
        ○ If full , print queue is full error
		○ If not full and is empty -> increment both rear and front  Store data into the queue array
		○ If not full and not empty -> increment rear 	Store data into the queue array
*/
int enqueue(ST_queue_t *queue,int data)
{
    if (isfull(queue))
    {
        return -1;          // Error
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front++;
            queue ->rear++;
            queue->element[queue->rear]=data;
        }
        else
        {
            queue ->rear++;
            queue->element[queue->rear]=data;
        }
        
    }
    return 0;   // Success
}

int dequeue(ST_queue_t *queue,int *data)
{
    /*
        removing data from front
    	○ If empty, print queue is empty error 
		○ If not empty and the last element -> read data from the queue 	Set rear and front to -1
		○ If not empty and not the last element -> read data from the queue	Increment the front
    */
    if (isEmpty(queue))
    {
        return -1;          //error
    }
    else
    {
        if (queue->rear == queue->front)
        {
            *data = queue->element[queue->front];
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            *data = queue->element[queue->front];
            queue ->front++;
        }
        
    }
    return 0;       //success    
}


// Function to print the elements of the queue
int printQueue(ST_queue_t *queue) 
{
    // If the queue is empty, print a message and return
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        if (isFull(queue)) {
        printf("Queue is full.\n");
        return -1;
    }
    // Print the elements of the queue starting from the front
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->element[i]);
    }
    printf("\n");
    return 0; // Success
}

/**
 * This function returns the front element of the queue without removing it.
 *
 * @param queue: pointer to the queue.
 * @return the front element of the queue.
 */
int getQueueFront(ST_queue_t *queue)
{
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->element[queue->front];
}

/**
 * This function returns the rear element of the queue without removing it.
 *
 * @param queue: pointer to the queue.
 * @return the rear element of the queue.
 */
int getQueueRear(ST_queue_t *queue)
{
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->element[queue->rear];
}
