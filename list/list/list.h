#pragma once

#include <stdbool.h>

typedef int Value;

typedef struct ListElement {
	Value value;
	struct ListElement* next;
} ListElement;

typedef struct List {
	ListElement* head;
} List;

typedef ListElement* Position;

List* createList(void);

Position first(List* list);

//function for adding an element
void add(List* list, Position position, Value value);

//function to get element value
Value getValue(List* list, Position position);

//function for changing the value of an element
void setValue(List* list, Position position, Value value);

//function that checks whether an element is the last
bool isLast(List* list, Position position);

//function checking the correctness of an item in the list
bool isValid(List* list, Position position);

//checks if the list is empty 
bool isEmpty(List* list);

//prints all elements of the list
void printList(List* list);

//adds an element at the end of the list
void addLast(List* list, Value value);

//removes the entire list and frees memory
void removeList(List* list);