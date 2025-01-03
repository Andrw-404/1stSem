#include "list.h"

#include <stdlib.h>

typedef struct ListElement {
    Value number;
    struct ListElement* next;
} ListElement;

ListElement* createListElement(Value number) {
    ListElement* newElement = malloc(sizeof(ListElement));
    if (newElement == NULL) {
        return NULL;
    }
    newElement->number = number;
    newElement->next = NULL;
    return newElement;
}

ListElement* createCircularList(int n) {
    if (n <= 0) {
        return NULL;
    }
    ListElement* head = createListElement(1);
    ListElement* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = createListElement(i);
        current = current->next;
    }
    current->next = head;
    return head;
}

void setNext(ListElement* element, ListElement* next) {
    if (element != NULL) {
        element->next = next;
    }
}

ListElement* getNext(Position element) {
    return element ? element->next : NULL;
}

Value getNumber(Position element) {
    return element ? element->number : -1;
}

void deleteCircularList(Position head) {
    if (head == NULL) {
        return;
    }
    ListElement* current = head;
    ListElement* tmp = head;
    do {
        tmp = current->next;
        free(current);
        current = tmp;
    } while (current != head);
}