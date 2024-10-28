#include "stack/testStack.h"
#include "advancedBracketBalance.h"
#include "testsForMainFunctions.h"

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!testCreateStack() || !testIsEmpty() || !testPop() || !testPush()) {
        printf("!Стек не прошел тесты!\n");
        return 10;
    }
    if (!testForHaveBrackets() || !testForBalance()) {
        printf("!Программа не прошла тесты!");
        return 11;
    }

    char string[100] = " ";
    printf("Введите строку: ");
    fgets(string, 100, stdin);
    if (haveBrackets(string)) {
        if (advancedBracketBalance(string)) {
            printf("\nБаланс скобок соблюдён\n\n");
        }
        else {
            printf("\nБаланс скобок не соблюдён\n\n");
        }
    }
    else {
        printf("\nВ строке скобок нет!\n\n");
    }
}
        