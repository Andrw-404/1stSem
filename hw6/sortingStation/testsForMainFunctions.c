#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "testsForMainFunctions.h"
#include "sortingStation.h"

bool testForIsOperator() {
    return isOperator('+') &&
        isOperator('-') &&
        isOperator('*') &&
        isOperator('/') &&
        !isOperator('s') &&
        !isOperator('(') &&
        !isOperator('[') &&
        !isOperator('_') &&
        !isOperator('.') &&
        !isOperator('#');
}

bool testForThePriorityFunction() {
    return (priority('+') == 1 && priority('-') == 1) &&
        (priority('*') == 2 && priority('/') == 2) &&
        (priority('(') == 0 && priority(')') == 0) &&
        (priority(']') == 0 && priority('[') == 0) &&
        (priority('?') == 0 && priority('^') == 0) &&
        (priority('>') == 0 && priority('<') == 0);
}

bool testForSortingStation() {
    char* firstResultForTest = sortingStation("1 + 1");
    if (strcmp(firstResultForTest, "1 1 + ") != 0) {
        free(firstResultForTest);
        return false;
    }
    free(firstResultForTest);

    char* secondResultForTest = sortingStation("(1 + 5) * 2");
    if (strcmp(secondResultForTest, "1 5 + 2 * ") != 0) {
        free(secondResultForTest);
        return false;
    }
    free(secondResultForTest);

    char* thirdResultForTest = sortingStation("(3 + 2) * (6 + 8)");
    if (strcmp(thirdResultForTest, "3 2 + 6 8 + * ") != 0) {
        free(thirdResultForTest);
        return false;
    }
    free(thirdResultForTest);

    char* fourthResultForTest = sortingStation("45 / (5 + 9)");
    if (strcmp(fourthResultForTest, "45 5 9 + / ") != 0) {
        free(fourthResultForTest);
        return false;
    }
    free(fourthResultForTest);

    return true;
}