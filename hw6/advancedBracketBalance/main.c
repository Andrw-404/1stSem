#include "stack/testStack.h"
#include "advancedBracketBalance.h"
#include "testsForMainFunctions.h"

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!testCreateStack() || !testIsEmpty() || !testPop() || !testPush()) {
        printf("!���� �� ������ �����!\n");
        return 10;
    }
    if (!testForHaveBrackets() || !testForBalance()) {
        printf("!��������� �� ������ �����!");
        return 11;
    }

    char string[100] = " ";
    printf("������� ������: ");
    fgets(string, 100, stdin);
    if (haveBrackets(string)) {
        if (advancedBracketBalance(string)) {
            printf("\n������ ������ �������\n\n");
        }
        else {
            printf("\n������ ������ �� �������\n\n");
        }
    }
    else {
        printf("\n� ������ ������ ���!\n\n");
    }
}
        