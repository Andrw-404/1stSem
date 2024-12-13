#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>

bool isValid(const char* inputString) {
    if (inputString[0] == '0' && strlen(inputString) > 1) {
        return false;
    }

    for (int i = 0; i < strlen(inputString); ++i) {
        if (!isdigit(inputString[i])) {
            return false;
        }
    }
    return true;
}
  

bool isPalindrome(int number) {
    if (number < 0) {
        return false;
    }

    int original = number;
    int reverse = 0;
    int helper = 0;

    while (number != 0) {
        helper = number % 10;
        reverse = reverse * 10 + helper;
        number /= 10;
    }

    return original == reverse;
}

bool testIsValid() {
    return !isValid("01") && 
        isValid("0") && 
        !isValid("001") && 
        isValid("143") && 
        isValid("4");
}

bool testIsPalindrome() {
    return isPalindrome(15451) &&
        !isPalindrome(123) &&
        isPalindrome(5) &&
        isPalindrome(12321) &&
        !isPalindrome(123421);

}
 
int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!testIsValid() || !testIsPalindrome()) {
        printf("!Тесты не пройдены!\n\n");
        return 1;
    }
    char inputString[100] = " ";
    int number = 0;
    printf("Введите число: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';

    if (!isValid(inputString)) {
        printf("Ошибка ввода\n\n");
        return 1;
    }
    
    number = atoi(inputString);

    if (isPalindrome(number)) {
        printf("\nЧисло %d является палиндромом\n\n", number);
    }
    else {
        printf("\nЧисло %d не является палиндромом\n\n", number);
    }
}
