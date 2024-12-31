#include "tree.h"
#include "tests.h"
#include "supportFunctions.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool testForCreateNode() {
    Node* root = createNode(4, "dq");
    if (root != NULL); {
        freeTree(root);
        return true;
    }
    freeTree(root);
    return false;
}

bool testForAdd() {
    Node* root = createNode(8, "q");

    root = add(root, 3, "1");
    root = add(root, 13, "u");
    root = add(root, 5, "t");
    root = add(root, 18, "4");
    root = add(root, 2, "ds");
    root = add(root, 10, "bcx");
    root = add(root, 5, "hi");

    Node* first = getLeftChild(root);
    int firstKey = getKey(first);
    char* firstValue = getCurrentElementValue(first);

    Node* second = getRightChild(root);
    int secondKey = getKey(second);
    char* secondValue = getCurrentElementValue(second);

    Node* third = getLeftChild(first);
    int thirdKey = getKey(third);
    char* thirdValue = getCurrentElementValue(third);

    Node* fourth = getRightChild(first);
    int fourthKey = getKey(fourth);
    char* fourthValue = getCurrentElementValue(fourth);

    Node* fifth = getLeftChild(second);
    int fifthKey = getKey(fifth);
    char* fifthValue = getCurrentElementValue(fifth);

    Node* sixth = getRightChild(second);
    int sixthKey = getKey(sixth);
    char* sixthValue = getCurrentElementValue(sixth);

    if ((firstKey == 3 && strcmp(firstValue, "1") == 0) &&
        (secondKey == 13 && strcmp(secondValue, "u") == 0) &&
        (thirdKey == 2 && strcmp(thirdValue, "ds") == 0) &&
        (fourthKey == 5 && strcmp(fourthValue, "hi") == 0) &&
        (fifthKey == 10 && strcmp(fifthValue, "bcx") == 0) &&
        (sixthKey == 18 && strcmp(sixthValue, "4") == 0)) {
        freeTree(root);
        return true;
    }
    freeTree(root);
    return false;
}

bool testForSearch() {
    Node* root = createNode(7, "root");
    root = add(root, 3, "c");
    root = add(root, 13, "u");
    root = add(root, 5, "t");
    root = add(root, 18, "y");

    Node* first = getLeftChild(root);
    Node* second = getRightChild(root);
    Node* third = getRightChild(first);
    Node* fourth = getRightChild(second);
    if (search(root, 3) == first &&
        search(root, 13) == second &&
        search(root, 5) == third &&
        search(root, 18) == fourth) {
        freeTree(root);
        return true;
    }
    freeTree(root);
    return false;
}

bool testForDeleteNode() {
    Node* root = createNode(7, "root");
    root = add(root, 3, "1");
    root = add(root, 13, "u");
    root = add(root, 5, "t");
    root = add(root, 18, "5");
    root = add(root, 2, "ds");
    root = add(root, 10, "bcx");
    root = add(root, 24, "hi");
    root = add(root, 1, "63");

    root = deleteNode(root, 3);
    root = deleteNode(root, 1);
    root = deleteNode(root, 5);
    root = deleteNode(root, 18);
    root = deleteNode(root, 2);
    root = deleteNode(root, 13);
    root = deleteNode(root, 24);
    root = deleteNode(root, 10);
    root = deleteNode(root, 7);
    
    if (root == NULL) {
        freeTree(root);
        return true;
    }
    freeTree(root);
    return false;
}

bool runTests() {
    bool tests[] = {
        testForCreateNode(),
        testForAdd(),
        testForSearch(),
        testForDeleteNode()
    };
    for (int i = 0; i < 4; ++i) {
        if (!tests[i]) {
            printf("Test %d failed\n\n", i);
            return false;
        }
    }
    return true;
}