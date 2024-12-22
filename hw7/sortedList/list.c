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
    list->head->next = NULL;
    return list;
}

Position first(List* list) {
    return list->head;
}

Position GetRealFirstElement(List* list) {
    return list->head->next;
}

Value getValue(List* list, Position position) {
    if (position == NULL) {
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

bool isLast(List* list, Position position) {
    return position->next == NULL;
}

bool isValid(List* list, Position position) {
    return position != NULL;
}

bool isEmpty(List* list) {
    return list == NULL || list->head->next == NULL;
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
    element->value = value;
    element->next = NULL;

    if (isEmpty(list)) {
        list->head->next = element;
    }
    else {
        ListElement* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = element;
    }
}

void removeList(List* list) {
    if (list == NULL) {
        return;
    }
    ListElement* current = list->head->next;
    while (current != NULL) {
        ListElement* next = current->next;
        free(current);
        current = next;
    }
    free(first(list));
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

void setNext(ListElement* element, ListElement* next) {
    if (element != NULL) {
        element->next = next;
    }
}

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
        printf("\n!!!Такой элемент не найден\n");
        return;
    }

    Position temp = current->next;
    current->next = temp->next;
    free(temp);
}