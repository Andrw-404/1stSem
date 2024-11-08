#pragma once

#include <stdbool.h>

typedef int Value;

typedef struct ListElement {
	char name[40];
	char phone[20];
	struct ListElement* next;
} ListElement;

typedef struct List {
	ListElement* head;
} List;

typedef ListElement* Position;

List* createList(void);

//function for adding an element
void addContact(List* list, char* name, char* phone);

//checks if the list is empty 
bool isEmpty(List* list);

//prints all elements of the list
void printList(List* list);

//removes the entire list and frees memory
void removeList(List* list);
