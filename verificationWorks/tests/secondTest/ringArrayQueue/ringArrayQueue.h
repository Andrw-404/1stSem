#pragma once

#include <stdbool.h>

typedef struct Queue Queue;

//function to add to the tail
void enqueue(Queue* queue, int value);

//function for taking an element from the head
int dequeue(Queue* queue);

//function for create queue
Queue* createQueue();

//function to change the queue size
void resize(Queue* queue);

//empty check function
bool isEmpty(Queue* queue);

//function for clearing the queue
void freeQueue(Queue* queue);