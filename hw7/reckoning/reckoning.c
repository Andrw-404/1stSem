#include "list.h"
#include "reckoning.h"

#include <stdlib.h>

int reckoning(List* list, int m) {
    if (isEmpty(list)) {
        return -1;
    }

    Position current = getNext(first(list));
    Position previous = getTail(list);

    while (current != previous) {
        for (int i = 1; i < m; ++i) {
            previous = current;
            current = getNext(current);

            if (current == first(list)) {
                current = getNext(current);
            }
        }

        Position delete = current;
        setNext(previous, getNext(current));
        current = getNext(previous);
        free(delete);

        if (current == first(list)) {
            current = getNext(current);
        }
    }
    int result = getValue(list, current);
    return result;
}
