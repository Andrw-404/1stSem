#include "tree.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    int key;
    char* value;
    struct Node* left;
    struct Node* right;
} Node;

int getKey(Node* position) {
    return position->key;
}

Node* createNode(int key, const char* value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->key = key;
    newNode->value = strdup(value);
    if (newNode->value == NULL) {
        return NULL;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* add(Node* root, int item, char* string) {
    if (root == NULL) {
        return createNode(item, string);
    }

    if (root->key == item) {
        free(root->value);
        root->value = strdup(string);
        if (root->value == NULL) {
            return NULL;
        }
        return root;
    }

    if (root->key > item) {
        root->left = add(root->left, item, string);
    }
    else if(root->key < item) {
        root->right = add(root->right, item, string);
    }
    return root;
}

Node* search(Node* root, int item) {
    if (root == NULL) {
        return NULL;
    }
    if (root->key == item) {
        return root;
    }
    if (item > root->key) {
        return search(root->right, item);
    }
    else if (item < root->key) {
        return search(root->left, item);
    }
    return NULL;
}

char* getValueByKey(Node* root, int key) {
    Node* foundNode = search(root, key);
    return foundNode ? foundNode->value : NULL;
}

bool checkTheKey(Node* root, int key) {
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

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < getKey(root)) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > getKey(root)) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root->value);
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            Node* tmp = root->right;
            free(root->value);
            free(root);
            return tmp;
        }
        else if (root->right == NULL) {
            Node* tmp = root->left;
            free(root->value);
            free(root);
            return tmp;
        }
        else {
            Node* tmp = findMin(root->right);
            root->key = tmp->key;
            free(root->value);
            root->value = malloc(strlen(tmp->value) + 1);
            strcpy(root->value, tmp->value);
            root->right = deleteNode(root->right, tmp->key);
        }
    }
    return root;
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root->value);
    free(root);
}

bool isEmpty(Node* root) {
    return root == NULL;
}

Node* getLeftChild(Node* root) {
    return root ? root->left : NULL;
}

Node* getRightChild(Node* root) {
    return root ? root->right : NULL;
}

char* getCurrentElementValue(Node* position) {
    return position->value;
}