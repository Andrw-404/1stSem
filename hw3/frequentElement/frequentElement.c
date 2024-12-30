#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define elementToSubtract -20


void feedArray(int* array, int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = (rand() % 100) + elementToSubtract;
	}
}

int frequentElement(int* array, int size) {
	int min = array[0];
	int max = array[0];
	for (int i = 0; i < size; ++i) {
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	int range = max - min + 1;
	int* countingArray = (int*)calloc(range, sizeof(int));
	if (countingArray == NULL) {
		printf("Ошибка выделения памяти\n\n");
		return -1;
	}

	for (int k = 0; k < size; ++k)
		++countingArray[array[k] - min];

	int maxCount = 0;
	int mostCommonElements = array[0];
	for (int j = 0; j < range; ++j)
		if (countingArray[j] > maxCount) {
			maxCount = countingArray[j];
			mostCommonElements = j + min;
		}

	free(countingArray);
	return mostCommonElements;
}

bool test() {
	int testArray[9] = { 1, 3, 4, 6, 1, 2, 5, 9, 1};
	int desired = 1;
	if (frequentElement(testArray, 9) != desired)
		return false;
	return true;
}

int main(void) {
	setlocale(LC_ALL, "RUS");

	if (!test()) {
		printf("Ошибка. Тест не пройден\n\n");
		return -1;
	}

	srand(time(NULL));
	int* array = (int*)calloc(101, sizeof(int));
	if (array == NULL) {
		printf("Ошибка выделения памяти\n\n");
		return -1;
	}
	int size = 54;
	feedArray(array, size);

	printf("Массив: \n");
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n\n\n");

	printf("Наиболее часто встречающийся элемент в массиве: %d\n\n", frequentElement(array, size));

	free(array);
}