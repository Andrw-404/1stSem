#pragma once

#include <stdbool.h>

typedef struct Dictionary Dictionary;

// function for connecting a node
Dictionary* add(Dictionary* node, const char* key, const char* value);

// function to find a node
Dictionary* search(Dictionary* node, const char* key);

// get node value
const char* getValue(Dictionary* node, const char* key);

// check if a node is present in a tree by key
bool checkTheKey(Dictionary* root, const char* key);

// function to remove a node from a tree
Dictionary* deleteNode(Dictionary* root, const char* key);

// function for deleting a tree
void freeTree(Dictionary* root);

// function to check if a tree is empty
bool isEmpty(Dictionary* root);

// function to check tree balance
bool isAVL(Dictionary* node);