#include <stdbool.h>

#include "parsingTree.h"

bool test() {
    int errorCode = 0;
    FILE* testFile = fopen("test.txt", "r");
    if (testFile == NULL) {
        return false;
    }
    Node* testRoot = expressionParse(testFile, &errorCode);
    fclose(testFile);
    int testResult = calculate(testRoot, &errorCode);
    if (testResult == 15 && errorCode == 0) {
        freeTree(testRoot);
        return true;
    }
    freeTree(testRoot);
    return false;
}