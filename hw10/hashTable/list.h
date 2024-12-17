#pragma once

#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

typedef int Value;

typedef ListElement* Position;

//function for create list with guardian
List* createList(void);

//adds an element at the end of the list
void addLast(List* list, char* key);

//removes the entire list and frees memory
void removeList(List* list);

//checks if the list is empty 
bool isEmpty(List* list);

//function returning the first element of the list
ListElement* getFirst(List* list);

//function that returns the element after the element passed to the function
ListElement* getNext(Position position);

//function that returns a string (in our case, the value of the table key)
char* getKey(Position position);

//function that returns the frequency
int getCount(Position position);

//function that allows you to change the frequency value
void setCount(Position position, int number);

//function that returns the length of the list
int getListLength(List* list);
