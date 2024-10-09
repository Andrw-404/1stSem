#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define MAX_VALUE 50000
#define MIN_VALUE -50001
#define VALUES_COUNT 100001


void bubbleSort(int* array, int arrayLength);
void countingSort(int* array, int arrayLength);
void feedArray(int* array, int arrayLength);


bool isSorted(int *array, int length) {
	for (int i = 0; i < length - 1; ++i) {
		if (array[i] > array[i + 1])
			return false;
	}
	return true;
}

bool test() {
	int testCount = 5;
	const int testLength = 100;
	int* firstTestArray = malloc(100 * sizeof(int));
	int* secondTestArray = malloc(100 * sizeof(int));
	if (firstTestArray == NULL || secondTestArray == NULL) {
		printf("Ошибка выделения памяти\n\n");
		return false;
	}

	for (int s = 0; s < testCount; ++s) {
		feedArray(firstTestArray, testLength);

		for (int i = 0; i < testLength; i++)
			secondTestArray[i] = firstTestArray[i];

		bubbleSort(firstTestArray, testLength);
		countingSort(secondTestArray, testLength);
		if (!isSorted(firstTestArray, testLength) || !isSorted(secondTestArray, testLength)) {
			free(firstTestArray);
			free(secondTestArray);
			return false;
		}
		++s;
	}

	free(firstTestArray);
	free(secondTestArray);
	return true;
}



void feedArray(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength; ++i) {
		array[i] = (rand() % VALUES_COUNT - 104) + MIN_VALUE;
	}
}


void bubbleSort(int* array, int arrayLength) {
	for (int i = 0; i < arrayLength - 1; ++i) {
		for (int k = 0; k < arrayLength - i - 1; ++k) {
			if (array[k] > array[k + 1]) {
				int temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
			}
		}
	}
}


void countingSort(int* array, int arrayLength) {
	int* countingArray = calloc(VALUES_COUNT, sizeof(int));
	if (countingArray == NULL) {
		printf("Ошибка выделения памяти\n\n");
		return;
	}

	for (int i = 0; i < arrayLength; ++i)
		++countingArray[array[i] - MIN_VALUE];
	int arrayPointer = 0;
	for (int i = 0; i < VALUES_COUNT; ++i) {
		int count = countingArray[i];
		for (int k = 0; k < count; ++k) {
			array[arrayPointer] = i + MIN_VALUE;
			++arrayPointer;
		}
	}
	free(countingArray);
}



int main(void) {
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	if (!test()) {
		printf("!!!Ошибка.Тест не пройден!!!\n\n");
		return 0;
	}
	const int arrayLength = 100000;



	int* arrayMain = malloc(arrayLength * sizeof(int));
	int* arrayCopy = malloc(arrayLength * sizeof(int));
	if (arrayMain == NULL || arrayCopy == NULL) {
		printf("Ошибка выделения памяти\n\n");
		return 1;
	}

	feedArray(arrayMain, arrayLength);
	for (int i = 0; i < arrayLength; i++)
		arrayCopy[i] = arrayMain[i];

	printf("---Сортировка пузырьком---\nПервые 30 элементов после сортировки пузырьком(Нужно подождать):\n");
	clock_t bubbleStart = clock();
	bubbleSort(arrayMain, arrayLength);
	clock_t bubbleEnd = clock();
	for (int l = 0; l < 30; l++) 
		printf("%d ", arrayMain[l]);
	printf("\n");
	printf("\nПоследние 30 элементов после сортировки пузырьком:\n");
	for (int q = arrayLength - 30; q < arrayLength; ++q)
		printf("%d ", arrayMain[q]);


	printf("\n\n\n\n\n---Сортировка подсчётом---\nПервые 30 элементов после сортировки подсчётом:\n");
	clock_t countingStart = clock();
	countingSort(arrayCopy, arrayLength);
	clock_t countingEnd = clock();
	for (int j = 0; j < 30; ++j)
		printf("%d ", arrayCopy[j]);
	printf("\n\nПоследние 30 элементов после сортировки подсчётом:\n");
	for (int c = arrayLength - 30; c < arrayLength; ++c)
		printf("%d ", arrayCopy[c]);


	double bubbleTime = (double)(bubbleEnd - bubbleStart) / CLOCKS_PER_SEC;
	double countingTime = (double)(countingEnd - countingStart) / CLOCKS_PER_SEC;

	printf("\n\nВремя работы сортировки пузырьком: %f\nВремя работы сортировки подсчетом: %f\n\n", bubbleTime, countingTime);

	free(arrayMain);
	free(arrayCopy);
}