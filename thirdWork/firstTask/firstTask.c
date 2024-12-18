#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int convert(const char* binaryString) {
    int decimal = 0;
    int length = strlen(binaryString);
    for (int i = 0; i < length; ++i) {
        decimal = decimal * 2;
        if (binaryString[i] == '1') {
            decimal += 1;
        }
    }
    return decimal;
}

void decimalToString(int decimal, char* decimalString) {
    sprintf(decimalString, "%d", decimal);
}

bool test() {
    char firstTestBinaryString[10] = "11011";
    int firstTestDecimal = convert(firstTestBinaryString);

    char secondTestBinaryString[10] = "001110";
    int secondTestDecimal = convert(secondTestBinaryString);

    char thirdTestBinaryString[10] = "11011111";
    int thirdTestDecimal = convert(thirdTestBinaryString);
    
    if (firstTestDecimal != 27 || secondTestDecimal != 14 || thirdTestDecimal != 223) {
        return false;
    }
    return true;
}


int main(void) {
    if (!test()) {
        printf("Test failed");
        return -1;
    }
    char binaryString[100] = "101110";
    int decimal = convert(binaryString);

    char decimalString[100] = " ";
    decimalToString(decimal, decimalString);

    printf("binary representation: %s\n\n", binaryString);
    printf("decimal representation: %s\n\n", decimalString);
}