#include <stdio.h>
#include <stdint.h>
#include <locale.h>
#include <stdbool.h>



void printBinary(int32_t number) {
	printf(" ");
	for (int i = 31; i >= 0; --i) {
		printf("%d", (number >> i) & 1);
	}
	printf("\n");
}

int bitwiseAddition(int32_t firstNum, int32_t secondNum) {
	int carry = 0;
	int result = 0;

	for (int i = 0; i < 32; ++i) {
		int bitFirstNum = (firstNum >> i) & 1;
		int bitSecondNum = (secondNum >> i) & 1;

		int sum = bitFirstNum + bitSecondNum + carry;
		int resultBit = sum % 2;
		carry = sum / 2;

		int mask = 1 << i;
		if (resultBit) 
			result |= mask;
		else 
			result &=~ mask;
		
	}
	
	return result;
}

bool overflowTestAssistant(int32_t firstNum, int32_t secondNum, int result) {
	if ((firstNum > 0 && secondNum > 0 && result < 0) || (firstNum < 0 && secondNum < 0 && result >= 0))
		return true;
	return false;
}



bool overflowTest(void) {
	int maxNum = INT32_MAX;
	int firstNumForOverflow = 1;
	int firstResultForOverflowTest = bitwiseAddition(maxNum, firstNumForOverflow);

	int minNum = INT32_MIN;
	int secondNumForOverlow = -1;
	int secondResultForOverflowTest = bitwiseAddition(minNum, secondNumForOverlow);

	if (!overflowTestAssistant(maxNum, firstNumForOverflow, firstResultForOverflowTest) 
		|| !overflowTestAssistant(minNum, secondNumForOverlow, secondResultForOverflowTest))
		return false;

	return true;

}

bool testWithExpectedNumbers(void) {
	int32_t firstTestNumbers = 7;
	int32_t secondTestNumbers = 9;
	int32_t firstExpectedNumber = 16;
	int firstTestResult = bitwiseAddition(firstTestNumbers, secondTestNumbers);

	int32_t thirdTestNumber = -26;
	int32_t fourthNumber = -8;
	int32_t secondExpectedNumber = -34;
	int secondTestResult = bitwiseAddition(thirdTestNumber, fourthNumber);

	int32_t fifthTestNumber = 53;
	int32_t sixthTestNumber = 0;
	int thirdExpectedResult = 53;
	int thirdTestResult = bitwiseAddition(fifthTestNumber, sixthTestNumber);

	int32_t seventhTestNumber = -46;
	int fourthExpectedResult = -46;
	int fourthTestResult = bitwiseAddition(seventhTestNumber, sixthTestNumber);

	if ((firstTestResult != firstExpectedNumber) || (secondTestResult != secondExpectedNumber) 
		|| (thirdTestResult != thirdExpectedResult) || (fourthTestResult != fourthExpectedResult)) {
		return false;
	}

	return true;
}

int main(void) {
	setlocale(LC_ALL, "RUS");
	
	if (!overflowTest() || !testWithExpectedNumbers()) {
		printf("!!!Ошибка.Тесты не пройдены!!!\n\n");
		return 1;
	}
	
	int32_t firstNumber = 0;
	int32_t secondNumber = 0;
	printf("Введите первое слагаемое: ");
	scanf_s("%d", &firstNumber);
	printf("\nВведите второе слагаемое: ");
	scanf_s("%d", &secondNumber);
	printf("\n\n");

	int result = bitwiseAddition(firstNumber, secondNumber);
	printBinary(firstNumber);
	printf("+\n");
	printBinary(secondNumber);
	printf(" ---------------------------------\n");

	printBinary(result);
	printf("\n\n\nСумма в десятичном виде: %d\n\n\n", result);
}