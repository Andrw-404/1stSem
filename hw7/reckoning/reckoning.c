#include "list.h"
#include "reckoning.h"

#include <stdio.h>

int reckoning(List* list, int m) {
    if (isEmpty(list)) {
        return -1;
    }
    Position current = list->head->next;
    while (current != current->next) {
        for (int i = 1; i < m - 1; ++i) {
            current = current->next;
        }
        Position kill = current->next;
        current->next = kill->next;
        free(kill);
        current = current->next;
    }
    return current->value;
}
    