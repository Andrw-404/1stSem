#include "parsingTree.h"

#include <stdlib.h>
#include <stdio.h>

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

Node* createOperationNode(char operation, Node* left, Node* right) {
    Node* newNode = malloc(sizeof(Node));
    newNode->operation = operation;
    newNode->value = 0;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* createNumberNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->operation = '\0';
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* expressionParse(FILE* file) {
    skipSpace(file);

    char current = fgetc(file);
    if (current == '(') {
        skipSpace(file);
        char operation = fgetc(file);

        Node* leftOperand = expressionParse(file);
        Node* rightOperand = expressionParse(file);

        skipSpace(file);
        fgetc(file);
        return createOperationNode(operation, leftOperand, rightOperand);
    }
    else {
        ungetc(current, file);
        int value = 0;
        fscanf(file, "%d", &value);
        return createNumberNode(value);
    }
}


int calculate(Node* node) {
    if (node->operation == '\0') {
        return node->value;
    }
    
    int leftValue = calculate(node->left);
    int rightValue = calculate(node->right);

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
            printf("Деление на ноль!\n");
            exit(1);
        }
        return leftValue / rightValue;
    default:
        printf("Неизвестная операция '%c'\n", node->operation);
        exit(1);
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