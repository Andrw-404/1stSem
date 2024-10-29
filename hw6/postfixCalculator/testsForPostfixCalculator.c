#include "testsForPostfixCalculator.h"
#include "postfixCalculator.h"

#include <stdbool.h>

bool calculatorTest() {
    char strForPlus[10] = "10 1 +";
    char strForMinus[10] = "10 3 -";
    char strForDivision[10] = "14 7 /";
    char firstStrForZero[10] = "6 0 *";
    char secondStrForPlus[10] = "0 6 *";
    char thirdStrForZero[10] = "0 5 /";
    char strForMultiplication[10] = "8 3 *";
    char strForPlusAndMultiplication[13] = "2 3 * 4 5 * +";


    return postfixCalculator(strForPlus) == 11 &&
        postfixCalculator(strForMinus) == 7 &&
        postfixCalculator(strForDivision) == 2 &&
        postfixCalculator(firstStrForZero) == 0 &&
        postfixCalculator(secondStrForPlus) == 0 &&
        postfixCalculator(thirdStrForZero) == 0 &&
        postfixCalculator(strForMultiplication) == 24 &&
        postfixCalculator(strForPlusAndMultiplication) == 26; 
}

bool testForOperatorChecking() {
    return operatorChecking("/") &&
        operatorChecking("+") &&
        operatorChecking("-") &&
        operatorChecking("*") &&
        !operatorChecking("{") &&
        !operatorChecking("}") &&
        !operatorChecking(".") &&
        !operatorChecking("[") &&
        !operatorChecking("(") &&
        !operatorChecking("@");
}
