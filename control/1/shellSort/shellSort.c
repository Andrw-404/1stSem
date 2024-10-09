﻿#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>



void feedArray(int* array, int size) {
	for (int i = 0; i < size; ++i)
		array[i] = (rand() % 153) - 47;
}


void shellSort(int* array, int size) {
	for (int step = size / 2; step > 0; step /= 2) {
		for (int i = step; i < size; ++i) {
			int temp = array[i];
			int k = 0;
			for (k = i; k >= step && array[k - step] > temp; k -= step) {
				array[k] = array[k - step];
			}
			array[k] = temp;
		}
	}
}


int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

bool sameness(int* firstArray, int* secondArray, int size) {
	for (int i = 0; i < size; ++i) {
		if (firstArray[i] != secondArray[i])
			return false;
	}
}

bool test() {
	int mainArray[50] = { 0 };
	int firstArray[50] = { 0 };
	int secondArray[50] = { 0 };
	int size = 50;

	feedArray(mainArray, size);
	memcpy(firstArray, mainArray, size);
	memcpy(secondArray, mainArray, size);

	qsort(firstArray, size, sizeof(int), compare);
	shellSort(secondArray, size);

	if (!sameness(firstArray, secondArray, size))
		return false;

	return true;

}


int main(void) {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	if (!test()) {
		printf("!!!Ошибка. Тест не пройден!!!");
		return -1;
	}

	int array[50] = { 0 };
	int size = sizeof(array) / sizeof(array[0]);

	feedArray(array, size);

	printf("Изначальный массив: ");
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);

	shellSort(array, size);

	printf("\n\nОтсортированный массив:\n");
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n\n\n");
}