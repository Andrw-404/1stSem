#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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


void addContact(List* list, char* name, char* phone) {
	if (list == NULL) {
		return;
	}
	ListElement* element = malloc(sizeof(ListElement));
	if (element == NULL) {
		return;
	}
	strcpy(element->name, name);
	strcpy(element->phone, phone);
	element->next = list->head;
	list->head = element;
}

bool isEmpty(List* list) {
	return list == NULL || list->head->next == NULL;
}

void printList(List* list) {
	if (isEmpty(list)) {
		printf("List is empty\n");
		return;
	}
	 Position current = list->head;
	 while (current != NULL) {
		 printf("%s %s\n", current->name, current->phone);
		 current = current->next;
	 }
}

void removeList(List* list) {
	if (list == NULL) {
		return;
	}
	ListElement* current = list->head;
	while (current != NULL) {
		ListElement* next = current->next;
		free(current);
		current = next;
	}
	free(list);
}
