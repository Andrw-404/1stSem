#include "list.h"
#include "reckoning.h"

#include <stdio.h>
#include <stdlib.h>

int reckoning(List* list, int m) {
    if (isEmpty(list)) {
        return -1;
    }

    Position current = getNext(first(list));
    Position previous = getTail(list);

    while (getNext(current) != current) {
        for (int i = 1; i < m; ++i) {
            previous = current;
            current = getNext(current);
        }

        Position nextPrev = getNext(previous);
        nextPrev = getNext(current);
        free(current);
        current = nextPrev;
    }
    int result = getValue(list, current);
    free(current);
    return result;
}
    