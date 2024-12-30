#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "AVLTree.h"

typedef struct Dictionary {
    const char* value;
    const char* key;
    Dictionary* left;
    Dictionary* right;
    int height;
} Dictionary;

void updateHeight(Dictionary* node) {
    if (node != NULL) {
        node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    }
}

int getBalance(Dictionary* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Dictionary* createDictionary(const char* value, const char* key) {
    Dictionary* newNode = malloc(sizeof(Dictionary));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->value = strdup(value);
    if (newNode->value == NULL) {
        free((char*)newNode->key);
        free(newNode);
        return NULL;
    }

    newNode->key = strdup(key);
    if (newNode->key == NULL) {
        free((char*)newNode->value);
        free(newNode);
        return NULL;
    }

    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Dictionary* rotateLeft(Dictionary* node) {
    Dictionary* rightChild = node->right;
    Dictionary* leftOfRight = rightChild->left;

    rightChild->left = node;
    node->right = leftOfRight;

    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
}

Dictionary* rotateRight(Dictionary* node) {
    Dictionary* leftChild = node->left;
    Dictionary* rightOfLeft = leftChild->right;

    leftChild->right = node;
    node->left = rightOfLeft;

    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
}

Dictionary* bigLeftRotate(Dictionary* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

Dictionary* bigRightRotate(Dictionary* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Dictionary* add(Dictionary* node, const char* key, const char* value) {
    if (key == NULL || value == NULL) {
        return NULL;
    }
    if (node == NULL) {
        return createDictionary(value, key);
    }

    int tmp = strcmp(key, node->key);

    if (tmp < 0) {
        node->left = add(node->left, key, value);
    }
    else if (tmp > 0) {
        node->right = add(node->right, key, value);
    }
    else {
        free((char*)node->value);
        node->value = strdup(value);
        if (node->value == NULL) {
            return NULL;
        }
        return node;
    }
    
    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && strcmp(key, node->left->key) < 0) {
        return rotateRight(node);
    }
    if (balance < -1 && strcmp(key, node->right->key) > 0) {
        return rotateLeft(node);
    }
    if (balance > 1 && strcmp(key, node->left->key) > 0) {
        return bigRightRotate(node);
    }
    if (balance < -1 && strcmp(key, node->right->key) < 0) {
        return bigLeftRotate(node);
    }

    return node;
}

Dictionary* search(Dictionary* node, const char* key) {
    if (node == NULL) {
        return NULL;
    }

    int tmp = strcmp(key, node->key);

    if (tmp == 0) {
        return node;
    }
    if (tmp > 0) {
        return search(node->right, key);
    }

    return search(node->left, key);
}

const char* getValue(Dictionary* node, const char* key) {
    Dictionary* foundNode = search(node, key);
    return foundNode ? foundNode->value : NULL;
}

bool checkTheKey(Dictionary* root, const char* key) {
    if (root != NULL) {
        return search(root, key) != NULL;
    }

    return false;
}

Dictionary* removeNode(Dictionary* root) {
    if (root->left == NULL || root->right == NULL) {
        Dictionary* tmp = root->left ? root->left : root->right;
        if (tmp == NULL) {
            free((char*)root->key);
            free((char*)root->value);
            free(root);
            return NULL;
        }
        else {
            root->key = strdup(tmp->key);
            root->value = strdup(tmp->value);
            root->left = tmp->left;
            root->right = tmp->right;
            free(tmp);
        }
    }
    else {
        Dictionary* tmp = root->right;
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }
        free((char*)root->key);
        free((char*)root->value);
        root->key = strdup(tmp->key);
        root->value = strdup(tmp->value);
        root->right = deleteNode(root->right, tmp->key);
    }

    return root;
}

Dictionary* deleteNode(Dictionary* root, const char* key) {
    if (root == NULL) {
        return root;
    }

    int tmp = strcmp(key, root->key);

    if (tmp < 0) {
        root->left = deleteNode(root->left, key);
    }
    else if (tmp > 0) {
        root->right = deleteNode(root->right, key);
    }
    else {
        root = removeNode(root);
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

void freeTree(Dictionary* root) {
    if (root == NULL) {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);

    free((char*)root->key);
    free((char*)root->value);
    free(root);
}

bool isEmpty(Dictionary* root) {
    return root == NULL;
}

int getHeight(Dictionary* node) {
    return node ? node->height : -1;
}