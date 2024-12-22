#pragma once

#include <stdbool.h>

typedef int Value;

typedef struct List List;

typedef struct ListElement ListElement;

typedef struct ListElement* Position;

// function for creating a list
List* createList(void);

// function for adding an element
void addContact(List* list, char* name, char* phone);

// checks if the list is empty 
bool isEmpty(List* list);

// prints all elements of the list
void printList(List* list);

// removes the entire list and frees memory
void removeList(List* list);

// function for getting the name of the transmitted contact
char* getName(ListElement* element);

// function for getting the phone number of a transmitted contact
char* getPhone(ListElement* element);

// function for getting the first element in the list
ListElement* getFirst(List* list);

// function to get the next element in the list
ListElement* getNext(Position position);

// function for getting a double pointer to an element
ListElement** getDoublePointer(Position element);

// function for changing the pointer to the next element
void setNext(ListElement* element, ListElement* next);