#include "list.h"
#include "testsForList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListElement {
    Value value;
    struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
    ListElement* tail;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = calloc(1, sizeof(ListElement));
    if (list->head == NULL) {
        free(list);
        return NULL;
    }
    list->head->next = list->head;
    list->tail = list->head;
    return list;
}

Position first(List* list) {
    return list->head;
}

void add(List* list, Position position, Value value) {
    if (list == NULL || position == NULL) {
        return;
    }
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return;
    }
    element->value = value;
    element->next = position->next;
    position->next = element;

    if (position == list->tail) {
        list->tail = element;
    }
}

Value getValue(List* list, Position position, int *errorCode) {
    if (position == NULL) {
        *errorCode = GET_VALUE_ERROR
        return (Value)0;
    }
    return position->value;
}

Position getNext(Position position) {
    return position->next;
}

void setValue(List* list, Position position, Value value) {
    position->value = value;
}

bool isValid(List* list, Position position) {
    return position != NULL;
}

bool isEmpty(List* list) {
    return list == NULL || list->tail == first(list);
}

void printList(List* list) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }
    Position current = list->head->next;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("end\n");
}

void addLast(List* list, Value value) {
    if (list == NULL) {
        return;
    }
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return;
    }
    element->value = value;

    if (list->tail == list->head) {
        list->head->next = element;
        element->next = list->head;
    }
    else  if (list->head->next == list->tail->next) {
        list->tail->next = element;
        element->next = list->head->next;
    }
    else {
        list->tail->next = element;
        element->next = list->head;
    }

    list->tail = element;
}

void removeList(List* list) {
    if (list == NULL) {
        return;
    }
    ListElement* current = list->head->next;
    while (current != list->head) {
        ListElement* next = current->next;
        free(current);
        current = next;
    }
    free(list->head);
    free(list);
}

Position getPositionByNumber(List* list, int number) {
    if (list == NULL || number <= 0) {
        return NULL;
    }
    Position current = list->head->next;
    for (int i = 1; current != NULL; ++i) {
        if (i == number) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Position getTail(List* list) {
    return list->tail;
}

void setNext(ListElement* element, ListElement* next) {
    if (element != NULL) {
        element->next = next;
    }
}

void removeListElement(List* list, Position position) {
    if (position->next != list->head) {
        Position tmp = position->next;
        position->next = tmp->next;
        free(tmp);
    }
}