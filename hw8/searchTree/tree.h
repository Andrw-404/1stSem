#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef Node* Position;

Node* createNode(int value, const char* string);

Node* add(Node* root, int item, char* string);

Node* search(Node* root, int item);

char* getValue(Node* root, int item);

bool checkTheKey(Node* root, int item);

Node* findMin(Node* root);

Node* deleteNode(Node* root, int item);

int getKey(Node* position);

void freeTree(Node* root);

bool isEmpty(Node* root);

Node* getLeftChild(Node* root);

Node* getRightChild(Node* root);

char* getCurrentElementValue(Node* position);