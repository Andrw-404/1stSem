#pragma once

#include <stdbool.h>

typedef struct ListElement ListElement;

typedef int Value;

typedef ListElement* Position;

// a function for creating a list element
ListElement* createListElement(Value number);

// function that returns the element after the element passed to the function
ListElement* getNext(Position element);

// function that changes the pointer to the next element
void setNext(ListElement* element, ListElement* next);

// a function for creating a cyclic list
ListElement* createCircularList(int n);

// the function for getting the item number
Value getNumber(Position element);

// a function for deleting a cyclic list
void deleteCircularList(Position head);