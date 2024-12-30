#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#include "/Proga/HW(1sem)/1stSem/stack/stack.h"
#include "postfixCalculator.h"

bool operatorChecking(char* token) {
    return (token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*');
}

bool divisorCheck(int divisor, char* token) {
    return (divisor == 0 && token[0] == '/');
}

int postfixCalculator(char* string) {
    Stack* stack = createStack();
    if (stack == NULL) {
        return false;
    }
    char* token = strtok(string, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(stack, atoi(token));
        }
        else if (!operatorChecking(token)) {
            free(stack);
            printf("\n!Неверный оператор!\n\n");
            return -1;
        }
        else {
            int rightNumber = pop(stack);
            int leftNumber = pop(stack);

            int result = 0;
            switch (token[0]) {
            case '+':
                result = leftNumber + rightNumber;
                break;
            case '-':
                result = leftNumber - rightNumber;
                break;
            case '/':
                if (divisorCheck(rightNumber, token)) {
                    printf("\nНа ноль делить нельзя!\n\n");
                    return -1;
                }
                else {
                    result = leftNumber / rightNumber;
                    break;
                }
            case '*':
                result = leftNumber * rightNumber;
                break;
            }

            push(stack, result);
        }
        token = strtok(NULL, " ");
    }
    if (isEmpty(stack)) {
        free(stack);
        return -1;
    }
    int final = pop(stack);
    free(stack);
    return final;
}