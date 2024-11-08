#include "list.h"
#include "reckoning.h"

#include <stdio.h>

int reckoning(List* list, int m) {
    if (isEmpty(list)) {
        return -1;
    }
    Position current = list->head->next;

    while (current->next != current) {
        for (int i = 1; i < m; ++i) {
            current = current->next;
        }
        Position removeElement = current->next;
        current->next = removeElement->next;
        free(removeElement);
        current = current->next;
    }
    int last = current->value;
    free(current);
    return last;
}