#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListElement {
    char name[40];
    char phone[20];
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
    return list;
}

void addContact(List* list, const char* name, const char* phone) {
    if (list == NULL) {
        return;
    }
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return;
    }
    strcpy(element->name, name);
    strcpy(element->phone, phone);
    element->next = list->head->next;
    list->head->next = element;
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
         printf("%s %s\n", current->name, current->phone);
         current = current->next;
     }
}

void removeList(List** list) {
    if (list == NULL || *list == NULL) {
        return;
    }

    ListElement* current = (*list)->head;
    while (current != NULL) {
        ListElement* next = current->next;
        free(current);
        current = next;
    }

    free(*list);
    *list = NULL;
}

const char* getName(ListElement* element) {
    return element ? element->name : NULL;
}

const char* getPhone(ListElement* element) {
    return element ? element->phone : NULL;
}
    
ListElement* getFirst(List* list) {
    return list ? list->head : NULL;
}

ListElement* getNext(Position position) {
    return position ? position->next : NULL;
}

void setNext(ListElement* element, ListElement* next) {
    if (element != NULL) {
        element->next = next;
    }
}

ListElement* createListElement(const char* name, const char* phone) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return NULL;
    }
    strncpy(element->name, name, sizeof(element->name) - 1);
    element->name[sizeof(element->name) - 1] = '\0';
    strncpy(element->phone, phone, sizeof(element->phone) - 1);
    element->phone[sizeof(element->phone) - 1] = '\0';
    element->next = NULL;
    return element;
}