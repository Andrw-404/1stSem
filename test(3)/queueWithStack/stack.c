#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

typedef struct StackElement {
	int value;
	struct StackElement* next;
} StackElement;

typedef struct Stack {
	StackElement* head;
} Stack;

void push(Stack* stack, int value) {
	StackElement* element = malloc(sizeof(StackElement));
	if (element == NULL) {
		return;
	}
	element->value = value;
	element->next = stack->head;
	stack->head = element;
}

int pop(Stack* stack) {
	if (stack->head == NULL) {
		return 1;
	}
	StackElement* tmp = stack->head;
	int value = tmp->value;
	stack->head = stack->head->next;
	free(tmp);
	return value;
}

Stack* createStack() {
	return (Stack*)calloc(1, sizeof(Stack));
}

bool isEmpty(Stack* stack) {
	return stack->head == NULL;
}