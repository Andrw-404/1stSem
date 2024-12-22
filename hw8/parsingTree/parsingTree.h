#pragma once

#include <stdio.h>

typedef struct Node Node;

// Skips spaces and newlines in the file
void skipSpace(FILE* file);

// Creates a node for the operation
Node* createOperationNode(char operation, Node* left, Node* right);

// creates a number node
Node* createNumberNode(int value);

// constructing a tree from an expression
Node* expressionParse(FILE* file);

// expression evaluation
int calculate(Node* node);

// tree removal
void freeTree(Node* node);

// tree removal
void printTree(Node* node);