#include "list.h"
#include "reckoning.h"

#include <stdio.h>

int reckoning(List* list, int m) {
    if (isEmpty(list)) {
        return -1;
    }
    Position current = list->head;
    while (current->next != list->head->next) {
        current = current->next;
    }
    while (current != current->next) {
        for (int i = 1; i < m - 1; ++i) {
            current = current->next;
        }
        Position kill = current->next;
        current->next = kill->next;
        if (current != current->next) {
            free(kill);
        }
    }
    return current->value;
}
    