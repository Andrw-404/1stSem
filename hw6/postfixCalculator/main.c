#include "/Proga/HW(1sem)/1stSem/stack/stack.h"
#include "postfixCalculator.h"
#include "testStack.h"
#include "testsForPostfixCalculator.h"

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!testCreateStack() || !testIsEmpty() || !testPop() || !testPush()) {
        printf("!���� �� ������ �����!\n");
        return 10;
    }

    if (!calculatorTest() || !testForOperatorChecking()) {
        printf("!�������� ������� �� ������ �����!\n");
        return 11;
    }

    char string[100] = " ";
    printf("������� ���������: ");
    fgets(string, 100, stdin);
    string[strcspn(string, "\n")] = 0;
    int answer = postfixCalculator(string);
    printf("�����: %d\n", answer);
}