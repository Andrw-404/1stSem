#include "tree.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    int key;
    char* string;
    struct Node* left;
    struct Node* right;
} Node;


int getKey(Node* position) {
    return position->key;
}

char* getCurrentString(Position position) {
    return position->string;
}

char* getString(Node* position) {
    return position->string;
}

Node* createNode(int value, const char* string) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = value;
    newNode->string = malloc(strlen(string) + 1);
    strcpy(newNode->string, string);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* add(Node* root, int item, char* string) {
    Node* existingNode = search(root, item);
    if (existingNode != NULL)  {
        strcpy(existingNode->string, string);
        return root;
    }

    if (root == NULL) {
        return createNode(item, string);
    }

    if (root->key > item) {
        root->left = add(root->left, item, string);
    }
    else  if(root->key < item) {
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

char* getValue(Node* root, int item) {
    Node* foundNode = search(root, item);
    return foundNode ? foundNode->string : NULL;
}

bool checkTheKey(Node* root, int item) {
    if (root != NULL) {
        return search(root, item) != NULL;
    }
    return false;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int item) {
    if (root == NULL) {
        return root;
    }

    if (item < getKey(root)) {
        root->left = deleteNode(root->left, item);
    }
    else if (item > getKey(root)) {
        root->right = deleteNode(root->right, item);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root->string);
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            Node* tmp = root->right;
            free(root->string);
            free(root);
            return tmp;
        }
        else if (root->right == NULL) {
            Node* tmp = root->left;
            free(root->string);
            free(root);
            return tmp;
        }
        else {
            Node* tmp = findMin(root->right);
            root->key = tmp->key;
            free(root->string);
            root->string = malloc(strlen(tmp->string) + 1);
            strcpy(root->string, tmp->string);
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

    free(root->string);
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
    return position->string;
}