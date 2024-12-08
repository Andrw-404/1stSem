#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

bool incompleteQuotient(int dividend, int divisor, int* quotient) {
    if (divisor == 0) {
        return false;
    }
    *quotient = 0;
    int sign = (dividend >= 0) == (divisor > 0) ? 1 : -1;
    int remainder = (dividend >= 0) ? dividend : -dividend;
    int absoluteDivisor = (divisor > 0) ? divisor : -divisor;
    while (remainder >= absoluteDivisor) {
        *quotient += sign;
        remainder -= absoluteDivisor;
    }
    if (sign == 1 && dividend < 0 && divisor < 0 && remainder > 0) {
        (*quotient)++;
    }
    return true;
}

int main(void) {
    int dividendInput, divisorInput, result = 0;
    setlocale(LC_ALL, "Russian");
    printf("Введите делимое: ");
    scanf_s("%d", &dividendInput);
    printf("\n");
    printf("Введите делитель: ");
    scanf_s("%d", &divisorInput);
    printf("\n");
    if (incompleteQuotient(dividendInput, divisorInput, &result)) {
        printf("Неполное частное: %d\n", result);
    }
    else {
        printf("Ошибка\n");
    }
    return 0;
}