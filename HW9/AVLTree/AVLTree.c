#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "AVLTree.h"

typedef struct Node{
    const char* value;
    const char* key;
    Node* left;
    Node* right;
    int height;
} Node;

void updateHeight(Node* node) {
    if (node != NULL) {
        node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    }
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* createNode(const char* value, const char* key) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->value = malloc(strlen(value) + 1);
    if (newNode->value == NULL) {
        return NULL;
    }
    strcpy((char*)newNode->value, value);

    newNode->key = malloc(strlen(key) + 1);
    if (newNode->key == NULL) {
        return NULL;
    }
    strcpy((char*)newNode->key, key);

    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* rotateLeft(Node* node) {
    Node* rightChild = node->right;
    Node* leftOfRight = rightChild->left;

    rightChild->left = node;
    node->right = leftOfRight;

    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
}

Node* rotateRight(Node* node) {
    Node* leftChild = node->left;
    Node* rightOfLeft = leftChild->right;

    leftChild->right = node;
    node->left = rightOfLeft;

    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
}

Node* bigLeftRotate(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

Node* bigRightRotate(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node* add(Node* node, const char* key, const char* value) {
    if (key == NULL || value == NULL) {
        return NULL;
    }
    if (node == NULL) {
        return createNode(value, key);
    }

    int num = atoi(key);
    int keyOfRoot = atoi(node->key);

    if (num < keyOfRoot) {
        node->left = add(node->left, key, value);
    }
    else if (num > keyOfRoot) {
        node->right = add(node->right, key, value);
    }
    else {
        strcpy((char*)node->value, value);
        return node;
    }
    
    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1) {
        if (num < atoi(node->left->key)) {
            return rotateRight(node);
        }
        return bigRightRotate(node);
    }
    if (balance < -1) {
        if (atoi(key) > atoi(node->right->key)) {
            return rotateLeft(node);
        }
        return bigLeftRotate(node);
    }

    return node;
}

Node* search(Node* node, const char* key) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(node->key, key) == 0) {
        return node;
    }
    if (strcmp(node->key, key) > 0) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

const char* getValue(Node* node, const char* key) {
    Node* foundNode = search(node, key);
    return foundNode ? foundNode->value : NULL;
}

bool checkTheKey(Node* root, const char* key) {
    if (root != NULL) {
        return search(root, key) != NULL;
    }
    return false;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, const char* key) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(key, root->key) < 0) {
        root->left = deleteNode(root->left, key);
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                free((char*)root->key);
                free((char*)root->value);
                free(root);
                return NULL;
            }
            else {
                *root = *temp;
                free(temp);
            }
        }
        else {
            Node* temp = findMin(root->right);
            strcpy((char*)root->key, temp->key);
            strcpy((char*)root->value, temp->value);
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    updateHeight(root);

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        return bigRightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        return bigLeftRotate(root);
    }

    return root;
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);

    free((char*)root->key);
    free((char*)root->value);
    free(root);
}

bool isEmpty(Node* root) {
    return root == NULL;
}

int getHeight(Node* node) {
    return node ? node->height : -111;
}