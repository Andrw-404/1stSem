#pragma once

#include <stdbool.h>

typedef struct Node Node;

// returns the balance of the tree
int getBalance(Node* node);

// creates a node
Node* createNode(const char* value, const char* key);

// small left rotate
Node* rotateLeft(Node* node);

// small right rotate
Node* rotateRight(Node* node);

// big left rotate
Node* bigLeftRotate(Node* node);

// bit right rotate
Node* bigRightRotate(Node* node);

// function for connecting a node
Node* add(Node* node, const char* key, const char* value);

// function to find a node
Node* search(Node* node, const char* key);

// get node value
const char* getValue(Node* node, const char* key);

// check if a node is present in a tree by key
bool checkTheKey(Node* root, const char* key);

// find the minimum node
Node* findMin(Node* root);

// function to remove a node from a tree
Node* deleteNode(Node* root, const char* key);

// function for deleting a tree
void freeTree(Node* root);

// function to check if a tree is empty
bool isEmpty(Node* root);

// function to get the height of a node
int getHeight(Node* node);

// function to update node height
void updateHeight(Node* node);