#pragma once

typedef struct Queue Queue;

int enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

Queue* createQueue();