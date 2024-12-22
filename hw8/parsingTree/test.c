#include <stdbool.h>

#include "parsingTree.h"

bool test() {
    FILE* testFile = fopen("test.txt", "r");
    if (testFile == NULL) {
        printf("Не удалось открыть тестовый файл\n\n");
        return;
    }
    Node* testRoot = expressionParse(testFile);
    fclose(testFile);
    int testResult = calculate(testRoot);
    if (testResult == 15) {
        freeTree(testRoot);
        return true;
    }
    freeTree(testRoot);
    return false;
}