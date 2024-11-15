#include "list.h"
#include "sortedList.h"

#include <stdlib.h>
#include <stdio.h>

void addElements(Value n, List* list) {
    if (list == NULL) {
        return;
    }

    ListElement* new = malloc(sizeof(ListElement));
    if (new == NULL) {
        return;
    }
    new->value = n;
    new->next = NULL;

    Position current = list->head;
    while (current->next != NULL && current->next->value < n) {
        current = current->next;
    }
    new->next = current->next;
    current->next = new;
}

void removeElement(Value n, List* list) {
    if (list == NULL || list->head->next == NULL) {
        return;
    }

    Position current = list->head;
    while (current->next != NULL && current->next->value != n) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Такой элемент не найден\n");

    }
    
    Position temp = current->next;
    current->next = temp->next;
    free(temp);
}