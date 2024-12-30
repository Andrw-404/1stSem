#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 void push(Stack* stack, int value) {
	StackElement* element = malloc(sizeof(StackElement));
	if (element == NULL) {
		return;
	}
	element->value = value;
	element->next = stack->head;
	stack->head = element;
}

void pop(Stack* stack) {
	if (stack->head == NULL) {
		return;
	}
	StackElement* tmp = stack->head;
	stack->head = stack->head->next;
	free(tmp);
}

Stack* createStack() {
	return (Stack*)calloc(1, sizeof(Stack));
}

bool isEmpty(Stack* stack) {
	return stack->head == NULL;
}

StackElement* top(Stack* stack) {
	return stack ? stack->head : NULL;
}