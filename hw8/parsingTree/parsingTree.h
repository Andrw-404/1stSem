#pragma once

#include <stdio.h>

typedef struct Node Node;

void skipSpace(FILE* file);

Node* createOperationNode(char operation, Node* left, Node* right);

Node* createNumberNode(int value);

Node* expressionParse(FILE* file);

int calculate(Node* node);

void freeTree(Node* node);

void printTree(Node* node);