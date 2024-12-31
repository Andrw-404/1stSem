#pragma once

// a function for getting the left child of a node
Node* getLeftChild(Node* root);

// a function for getting the right child of a node
Node* getRightChild(Node* root);

// function for getting the value of the passed node
char* getCurrentElementValue(Node* position);

// the function for obtaining the key of the transmitted node
int getKey(Node* position);

// a function for creating a node
Node* createNode(int key, const char* value);

// a function for searching a node in a tree by key
Node* search(Node* root, int item);