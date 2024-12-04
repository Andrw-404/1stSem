#include "ringQueue.h"

#include <stdio.h>

int main(void) {
    Queue* queue = createQueue();
    enqueue(queue, 1);
    int res = dequeue(queue);
}