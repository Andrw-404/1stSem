#pragma once

#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

typedef int Value;

typedef ListElement* Position;

//function to create a list
List* createList(void);

//function returning the head of the list
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

//function converting a single-linked list into a cyclic list
void makeACircularList(List* list);

//function that returns the element after the element passed to the function
Position getNext(Position position);

//function that returns an item by its sequence number in the list
Position getPositionByNumber(List* list, int number);