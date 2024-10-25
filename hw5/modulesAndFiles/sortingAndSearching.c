#include "sortingAndSearching.h"

#include <stdlib.h>
#include <stdio.h>

int frequentElement(int* array, int size) {
	int min = array[0];
	int max = array[0];
	for (int i = 0; i < size; ++i) {
		if (array[i] < min) {
			min = array[i];
		}
		if (array[i] > max) {
			max = array[i];
		}
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