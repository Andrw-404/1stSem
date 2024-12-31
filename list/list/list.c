#include "list.h"
#include "testsForList.h"

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

Position first(List* list) {
	return list ? list->head : NULL;
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
}

Value getValue(List* list, Position position) {
	if (position == NULL) {
		return (Value)0;
	}
	return position->value;
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
	ListElement* current = list->head;
	while (current != NULL) {
		ListElement* next = current->next;
		free(current);
		current = next;
	}
	free(list);
}