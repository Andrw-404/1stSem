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


int height(Node* node) {
    return node ? node->height : 0;
}

void addHeight(Node* node) {

    if (node->left == NULL && node->right == NULL) {
        return;
    }
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
}

int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->right == NULL || node->left == NULL) {
        return node->height;
    }
    return height(node->left) - height(node->right);
}

Node* createNode(const char* value, const char* key) {
    Node* newNode = malloc(sizeof(Node));

    newNode->value = malloc(strlen(value) + 1);
    strcpy(newNode->value, value);
    newNode->key = malloc(strlen(key) + 1);
    strcpy(newNode->key, key);
    newNode->height = 0;

    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* rotateLeft(Node* node) {
    if (node == NULL || node->right == NULL) {
        return node;
    }
    Node* rightChild = node->right;
    Node* leftChildOfTheRightSubtree = rightChild->left;
    rightChild->left = node;
    node->right = leftChildOfTheRightSubtree;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    rightChild->height = 1 + (height(rightChild->left) > height(rightChild->right) ? height(rightChild->left) : height(rightChild->right));

    return rightChild;
}

Node* rotateRight(Node* node) {
    if (node == NULL || node->left == NULL) {
        return node;
    }
    Node* leftChild = node->left;
    Node* rightChildOfTheLeftSubtree = leftChild->right;
    leftChild->right = node;
    node->left = rightChildOfTheLeftSubtree;
    
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    leftChild->height = 1 + (height(leftChild->left) > height(leftChild->right) ? height(leftChild->left) : height(leftChild->right));

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

    Node* existingNode = search(node, key);
    if (existingNode != NULL) {
        strcpy(existingNode->value, value);
        return node;
    }

    if (keyOfRoot > num) {
        node->left = add(node->left, key, value);
    }

    if (keyOfRoot < num) {
        node->right = add(node->right, key, value);
    }
    
    addHeight(node);

    int balance = getBalance(node);

    if (balance < -1) {
        if (node->left != NULL && strcmp(key, node->left->key) < 0) {
            return rotateRight(node);
        }
        return bigRightRotate(node);
    }

    if (balance > 1) {
        if (node->right != NULL && strcmp(key, node->right->key) > 0) {
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
    else if (strcmp(node->key, key) > 0) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
    return NULL;
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
        if (root->left == NULL && root->right == NULL) {
            free((char*)root->key);
            free((char*)root->value);
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            Node* tmp = root->right;
            free((char*)root->key);
            free((char*)root->value);
            free(root);
            return tmp;
        }
        else if (root->right == NULL) {
            Node* tmp = root->left;
            free((char*)root->key);
            free((char*)root->value);
            free(root);
            return tmp;
        }
        else {
            Node* tmp = findMin(root->right);
            free((char*)root->key);
            root->key = malloc(strlen(tmp->key) + 1);
            strcpy((char*)root->key, tmp->key);

            free((char*)root->value);
            root->value = malloc(strlen(tmp->value) + 1);
            strcpy(root->value, tmp->value);
            root->right = deleteNode(root->right, tmp->key);
        }
    }

    int balance = getBalance(root);
    if (balance < -1 && getBalance(root->left) <= 0) {
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->right) >= 0) {
        return rotateLeft(root);
    }

    if (balance > 1 && getBalance(root->right) < 0) {
        return bigLeftRotate(root);
    }

    if (balance < -1 && getBalance(root->left) > 0) {
        return bigRightRotate(root);
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
    return node->height;
}