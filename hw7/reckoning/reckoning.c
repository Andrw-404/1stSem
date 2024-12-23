#include "list.h"
#include "reckoning.h"

#include <stdlib.h>

int reckoning(List* list, int m, int* errorCode) {
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
        removeListElement(list, previous);
        current = getNext(previous);
    }

    int result = getValue(list, current, errorCode);
    free(current);
    return result;
}