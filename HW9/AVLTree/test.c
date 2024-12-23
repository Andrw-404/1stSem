#include "AVLTree.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool testForAdd() {
    Node* testRoot = NULL;
    testRoot = add(testRoot, "10", "aaa");
    testRoot = add(testRoot, "4", "bbb");
    testRoot = add(testRoot, "43", "ccc");
    if (strcmp(getValue(testRoot, "10"), "aaa") == 0 &&
        strcmp(getValue(testRoot, "4"), "bbb") == 0 &&
        strcmp(getValue(testRoot, "43"), "ccc") == 0) {
        freeTree(testRoot);
        return true;
    }
    freeTree(testRoot);
    return false;
}

bool testForSearch() {
    Node* testRoot = NULL;
    testRoot = add(testRoot, "10", "aaa");
    testRoot = add(testRoot, "4", "bbb");
    testRoot = add(testRoot, "43", "ccc");
    if (checkTheKey(testRoot, "10") &&
        checkTheKey(testRoot, "4") &&
        checkTheKey(testRoot, "43") &&
        !checkTheKey(testRoot, "100")) {
        freeTree(testRoot);
        return true;
    }
    freeTree(testRoot);
    return false;
}

bool deleteNodeTest() {
    Node* testRoot = NULL;
    testRoot = add(testRoot, "10", "aaa");
    testRoot = add(testRoot, "4", "bbb");
    testRoot = add(testRoot, "43", "ccc");
    testRoot = add(testRoot, "765", "ddd");

    if (!checkTheKey(testRoot, "10") &&
        !checkTheKey(testRoot, "4") &&
        !checkTheKey(testRoot, "43") &&
        !checkTheKey(testRoot, "765")) {
        freeTree(testRoot);
        return false;
    }

    testRoot = deleteNode(testRoot, "765");

    if (checkTheKey(testRoot, "10") &&
        checkTheKey(testRoot, "4") &&
        checkTheKey(testRoot, "43") &&
        !checkTheKey(testRoot, "765")) {
        freeTree(testRoot);
        return true;
    }
    freeTree(testRoot);
    return false;
}

bool runTests() {
    bool tests[3] = { testForAdd(),
        testForSearch(),
        deleteNodeTest()
    };
    for (int i = 0; i < 2; ++i) {
        if (!tests[i]) {
            printf("Test %d is failed\n\n", i);
            return false;
        }
    }
    return true;
}