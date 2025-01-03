#pragma once

#include <stdbool.h>

typedef struct Stack Stack;

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

typedef struct Stack {
    StackElement* head;
} Stack;

Stack* createStack();

//function adds an item to the stack
void push(Stack* stack, int value);

//function removes an item from the stack
int pop(Stack* stack);

//function checks if the stack is empty
bool isEmpty(Stack* stack);