#pragma once

#include <stdbool.h>

typedef int Value;

typedef struct List List;

typedef struct ListElement ListElement;

typedef struct ListElement* Position;

// function for creating a list
List* createList(void);

// function for adding an element
void addContact(List* list, const char* name, const char* phone);

// checks if the list is empty 
bool isEmpty(List* list);

// prints all elements of the list
void printList(List* list);

// removes the entire list and frees memory
void removeList(List** list);

// function for getting the name of the transmitted contact
const char* getName(ListElement* element);

// function for getting the phone number of a transmitted contact
const char* getPhone(ListElement* element);

// function for getting the first element in the list
ListElement* getFirst(List* list);

// function to get the next element in the list
ListElement* getNext(Position position);

// function for changing the pointer to the next element
void setNext(ListElement* element, ListElement* next);

// accepts the name and number and returns the contact with these details
ListElement* createListElement(const char* name, const char* phone);