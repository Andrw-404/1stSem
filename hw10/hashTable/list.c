#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct ListElement {
	char* key;
	int count;
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

void addLast(List* list, char* key) {
	if (list == NULL) {
		return;
	}
	ListElement* element = malloc(sizeof(ListElement));
	char* string = malloc(sizeof(key));
	strcpy(string, key);
	element->key = string;
	element->next = NULL;
	element->count = 1;
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
	ListElement* current = list->head;
	while (current != NULL) {
		ListElement* next = current->next;
		free(current);
		current = next;
	}
	free(list);
}

bool isEmpty(List* list) {
	return list == NULL || list->head->next == NULL;
}

ListElement* getFirst(List* list) {
	return list ? list->head->next : NULL;
}

ListElement* getNext(Position position) {
	return position ? position->next : NULL;
}

char* getKey(Position position) {
	return position ? position->key : NULL;
}

int getCount(Position position) {
	return position ? position->count : -1;
}

void setCount(Position position, int number) {
	if (position == NULL) {
		return;
	}
	position->count = getCount(position) + number;
}

int getListLength(List* list) {
	if (list == NULL) {
		return -1;
	}
	int length = 0;
	ListElement* current = getFirst(list);
	while (current != NULL) {
		++length;
		current = getNext(current);
	}
	return length;
}
