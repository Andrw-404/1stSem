#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Queue {
    Stack* firstStack;
    Stack* secondStack;
};

int enqueue(Queue* queue, int value) {
    push(queue->firstStack, value);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue->secondStack)) {
        int temp = pop(queue->firstStack);
        while (temp != NULL) {
            push(queue->firstStack);
            temp = pop(queue->firstStack);
        }
    }
    pop(queue->secondStack);
}

void deleteQueue(Queue* queue) {
    while (!isEmpty(queue->firstStack) && !isEmpty(queue->secondStack)) {
    }
}

Queue* createQueue() {
    return (Queue*)calloc(1, sizeof(Queue));
}