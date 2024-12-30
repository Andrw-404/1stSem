#include "sortingStation.h"
#include "testStack.h"
#include "testsForMainFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!testCreateStack() || !testIsEmpty() || !testPop() || !testPush()) {
        printf("!���� �� ������ �����!\n\n");
        return 10;
    }
    if (!testForSortingStation() || !testForIsOperator() || !testForThePriorityFunction()) {
        printf("!�������� ������� �� ������ �����!\n\n");
        return 10;
    }

    char string[100] = " ";
    printf("������� ������: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    char* output = sortingStation(string);
    printf("%s\n\n", output);
    free(output);
}