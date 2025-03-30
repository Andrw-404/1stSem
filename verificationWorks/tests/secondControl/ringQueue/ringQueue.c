#include "ringQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STARTSIZE 10

typedef struct Queue {
	int* array;
	int first;
	int back;
	int count;
	int size;
} Queue;

Queue* createQueue() {
	Queue* queue = malloc(sizeof(Queue));
	if (queue == NULL) {
		return;
	}
	queue->array = malloc(10 * sizeof(int));
	if (queue->array == NULL) {
		return;
	}
	queue->size = STARTSIZE;
	queue->count = 0;
	queue->first = 0;
	queue->back = 0;
	return queue;
}

void resize(Queue* queue) {
	int newSize = (queue->size) * 2;
	int* newArray = realloc(queue->array, newSize * sizeof(int));
	if (newArray == NULL) {
		return;
	}
	if (queue->first > queue->back) {
		for (int i = 0; i < queue->first; ++i) {
			newArray[queue->size + i] = queue->array[i];
		}
		queue->back += queue->size;
	}
	queue->array = newArray;
	queue->size = newSize;
}

void enqueue(Queue* queue, int value) {
	if (queue->size == (queue->count + 1)) {
		resize(queue);
	}

	queue->array[queue->back] = value;
	queue->back = (queue->back + 1) % queue->size;
	queue->count++;
}

bool isEmpty(Queue* queue) {
	return queue->count == 0;
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		return NULL;
	}
	int element = 0;
	element = queue->array[queue->first];
	queue->first = (queue->first + 1) % queue->size;
	queue->count--;
	return element;
}

void freeQueue(Queue* queue) {
	free(queue->array);
	queue->array = NULL;
	queue->size = 0;
	queue->count = 0;
	queue->first = 0;
	queue->back = 0;
}