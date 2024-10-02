#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

void halfQsort(int array[], int size); //прототип функции

bool testHalfQsort() {
	int testArray[7] = { 4, 2, 1, 7, 5, 6, 3 };
	int testBased = testArray[0];
	halfQsort(testArray, 7);
	return (testBased > testArray[0] && testBased > testArray[1] && testBased > testArray[2] && testBased <= testArray[3]
		&& testBased <= testArray[4] && testBased <= testArray[5] && testBased <= testArray[6]);
}

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void initializationArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
}

void arrayPrinter(int array[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
}

void halfQsort(int array[], int size) {
	int i =	1;
	int j = size - 1;
	int basedNumber = array[0];
	while (i <= j) {
		while ((i <= j) && (basedNumber > array[i]))
			i++;
		while ((i <= j) && (basedNumber <= array[j]))
			j--;
		if (i <= j) {
			swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
	swap(&array[0], &array[j]);
}

int main(void) {
	setlocale(LC_ALL, "Russian");

	if (!testHalfQsort()) {
		printf("\n\n!!!Ошибка. Тест не пройден!!!\n\n");
		exit(1);
	}

	int array[10] = { 0 };
	initializationArray(array, 10);
	printf("\nИсходный массив: ");

	arrayPrinter(array, 10);

	halfQsort(array, 10);
	printf("\n\n");
	printf("\nОтсортированный массив: ");

	arrayPrinter(array, 10);
	printf("\n\n");
}