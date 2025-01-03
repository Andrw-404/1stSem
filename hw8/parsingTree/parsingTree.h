#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MEMORY_ERROR 1
#define FILE_ERROR 2
#define DIVISION_ERROR 3
#define OPERATION_ERROR 4

typedef struct Node Node;

// Skips spaces and newlines in the file
void skipSpace(FILE* file);

// Creates a node for the operation
Node* createOperationNode(char operation, Node* left, Node* right, int* errorCode);

// creates a number node
Node* createNumberNode(int value, int* errorCode);

// constructing a tree from an expression
Node* expressionParse(FILE* file, int* errorCode);

// expression evaluation
int calculate(Node* node, int* errorCode);

// tree removal
void freeTree(Node* node);

// tree removal
void printTree(Node* node);

// function for displaying the error name
bool verify(int* errorCode);