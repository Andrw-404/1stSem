#pragma once

#include <stdbool.h>

typedef struct Node Node;

int height(Node* node);

int getBalance(Node* node);

Node* createNode(const char* value, const char* key);

Node* rotateLeft(Node* node);

Node* rotateRight(Node* node);

Node* bigLeftRotate(Node* node);

Node* bigRightRotate(Node* node);

Node* add(Node* node, const char* key, const char* value);

Node* search(Node* node, const char* key);

const char* getValue(Node* node, const char* key);

bool checkTheKey(Node* root, const char* key);

Node* findMin(Node* root);

Node* deleteNode(Node* root, const char* key);

void freeTree(Node* root);

bool isEmpty(Node* root);

int getHeight(Node* node);

void addHeight(Node* node);