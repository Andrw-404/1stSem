#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef Node* Position;

// a function for adding a node to a tree
Node* add(Node* root, int item, char* string);

// a function for getting the node value by key
char* getValueByKey(Node* root, int key);

// a function that checks for a node with a given key
bool checkTheKey(Node* root, int item);

// a function for deleting a node with a given key
Node* deleteNode(Node* root, int key);

// a function for deleting a tree
void freeTree(Node* root);

// a function for checking the emptiness of a tree
bool isEmpty(Node* root);