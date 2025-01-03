#include "parsingTree.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    char operation;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

void skipSpace(FILE* file) {
    char tmp = ' ';
    while ((tmp = fgetc(file)) == ' ' || tmp == '\n');
    ungetc(tmp, file);
}

Node* createOperationNode(char operation, Node* left, Node* right, int *errorCode) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        *errorCode = MEMORY_ERROR;
        return NULL;
    }
    newNode->operation = operation;
    newNode->value = 0;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* createNumberNode(int value, int* errorCode) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        *errorCode = MEMORY_ERROR;
        return NULL;
    }
    newNode->operation = '\0';
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* expressionParse(FILE* file, int* errorCode) {
    skipSpace(file);

    char current = fgetc(file);
    if (current == '(') {
        skipSpace(file);
        char operation = fgetc(file);

        skipSpace(file);
        Node* leftOperand = expressionParse(file, errorCode);

        skipSpace(file);
        Node* rightOperand = expressionParse(file, errorCode);

        skipSpace(file);
        if (fgetc(file) != ')') {
            *errorCode = FILE_ERROR;
            return NULL;
        }
        return createOperationNode(operation, leftOperand, rightOperand, errorCode);
    }
    else {
        ungetc(current, file);
        int value = 0;
        if (fscanf(file, "%d", &value) != 1) {
            *errorCode = FILE_ERROR;
            return NULL;
        }
        return createNumberNode(value, errorCode);
    }
}

int calculate(Node* node, int* errorCode) {
    if (node->operation == '\0') {
        return node->value;
    }
    
    int leftValue = calculate(node->left, errorCode);
    int rightValue = calculate(node->right, errorCode);

    switch (node->operation)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        if (rightValue == 0) {
            *errorCode = DIVISION_ERROR;
            return -1;
        }
        return leftValue / rightValue;
    default:
        *errorCode = OPERATION_ERROR;
        return -3;
    }
}

void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }

    freeTree(node->left);
    freeTree(node->right);

    free(node);
}

void printTree(Node* node) {
    if (node == NULL) {
        return;
    }

    if (node->operation == '\0') {
        printf("%d", node->value);
    }
    else {
        printf("( %c ", node->operation);
        printTree(node->left);
        printf(" ");
        printTree(node->right);
        printf(" )");
    }
}

bool verify(int* errorCode) {
    switch (*errorCode) {
    case 1:
        printf("MEMORY_ERROR\n\n");
        return false;
    case 2:
        printf("FILE_ERROR\n\n");
        return false;
    case 3:
        printf("DIVISION_ERROR\n\n");
        return false;
    case 4:
        printf("OPERATION_ERROR\n\n");
        return false;
    case 0:
        return true;
    default:
        printf("UNKNOWN_ERROR\n\n");
        return false;
    }
}