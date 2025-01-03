#include "list.h"
#include "reckoning.h"

#include <stdlib.h>

int reckoning(int n, int m) {
    ListElement* head = createCircularList(n);
    ListElement* current = head;

    while (current != getNext(current)) {
        for (int i = 1; i < m - 1; ++i) {
            current = getNext(current);
        }
        ListElement* killPosition = getNext(current);
        setNext(current, getNext(killPosition));
        free(killPosition);
        current = getNext(current);
    }

    int result = getNumber(current);
    free(current);
    return result;
}
