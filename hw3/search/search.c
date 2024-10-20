#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>


void feedArray(int* array, int size) {
	for (int i = 0; i < size; ++i)
		array[i] = rand() % 169 - 78;
}



void insertSort(int* array, int right) {
	for (int i = 1; i <= right; ++i) {
		for (int k = i; k > 0 && array[k - 1] > array[k]; --k) {
			int tmp = array[k];
			array[k] = array[k - 1];
			array[k - 1] = tmp;
		}
	}
}

void smartQSort(int* array, int left, int right) {
	if ((right - left) < 11) {
		insertSort(array, right);
		return;
	}
	if (left >= right)
		return;
	int pivot = array[(left + right) / 2];
	int i = left;
	int k = right;

	while (i <= k) {
		while (array[i] < pivot)
			++i;
		while (array[k] > pivot)
			--k;
		if (i <= k) {
			int temp = array[i];
			array[i] = array[k];
			array[k] = temp;
			++i;
			--k;
		}
	}
	smartQSort(array, left, k);
	smartQSort(array, i, right);
}

int search(int* memoryForN, int value, int n) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int middle = left + (right - left) / 2;
		if (memoryForN[middle] == value)
			return 1;
		if (memoryForN[middle] > value)
			right = middle - 1;
		if (memoryForN[middle] < value)
			left = middle + 1;
	}
	return 0;
}

bool sameness(int* array1, int* array2, int length) {
	for (int i = 0; i < length; ++i) {
		if (array1[i] != array2[i])
			return false;
	}
	return true;
}


bool testForSort() {
	int arrayForSort[10] = { 7,4,1,0,-4,-1,9,3,2,10 };
	int sortedArray[10] = { -4,-1,0,1,2,3,4,7,9,10 };
	smartQSort(arrayForSort, 0, 9);
	return (sameness(sortedArray, arrayForSort, 10));
}

bool testSearch() {
	int array[10] = { -5,-3,-1,0,1,3,6,8,10,11 };
	for (int i = 0; i < 10; ++i) {
		if (!search(array, array[i], 10))
			return false;
	}

	if (search(array, -6, 10) || search(array, 12, 10))
		return false;

	return true;
}

bool testSingleElement() {
	int firstArrayWithSingleElement[] = { 30 };
	return search(firstArrayWithSingleElement, 30, 1);
}

bool testSingleElementNotFound() {
	int secondArrayWithSingleElement[] = { 30 };
	return(!search(secondArrayWithSingleElement, 0, 1));
}

bool testRepetitiveElements() {
	int arrayWithRepetitiveElements[8] = { 0,2,2,3,2,4,7,-1 };
	return search(arrayWithRepetitiveElements, 2, 8);
}



int main(void) {
	setlocale(LC_ALL, "RUS");
	if (!testForSort() || !testSearch() || !testSingleElement() || !testSingleElementNotFound()
		|| !testRepetitiveElements()) {
		printf("!!!Тест не пройден!!!\n\n");
		return -1;
	}
	srand(time(NULL));
	int n = 0;
	do {
		printf("\nВведите n: ");
		scanf_s("%d", &n);
		if (n <= 0)
			printf("\nЧисло должно быть больше 0\n\n");
	} while (n <= 0);
	int* memoryForN = (int*)calloc(n, sizeof(int));

	int k = 0;
	do {
		printf("\nВведите k: ");
		scanf_s("%d", &k);
		if (k <= 0)
			printf("\nЧисло должно быть больше 0\n\n");
	} while (k <= 0);
	int* memoryForK = (int*)calloc(k, sizeof(int));

	feedArray(memoryForN, n);
	feedArray(memoryForK, k);


	smartQSort(memoryForN, 0, n - 1);


	int* found = (int*)calloc(k, sizeof(int));
	int* notFound = (int*)calloc(k, sizeof(int));
	int foundCounter = 0;
	int notFoundCounter = 0;

	for (int z = 0; z < k; ++z) {
		if (search(memoryForN, memoryForK[z], n)) {
			found[foundCounter] = memoryForK[z];
			++foundCounter;
		}
		else {
			notFound[notFoundCounter] = memoryForK[z];
			++notFoundCounter;
		}
	}




	printf("\n\n===Найдены в массиве n===\n");
	for (int q = 0; q < foundCounter; ++q) {
		printf("%d ", found[q]);
	}

	printf("\n\n===НЕ найдены в массиве n===\n");
	for (int w = 0; w < notFoundCounter; ++w) {
		printf("%d ", notFound[w]);
	}

	printf("\n\n\n");

	free(memoryForN);
	free(memoryForK);
	free(found);
	free(notFound);
}