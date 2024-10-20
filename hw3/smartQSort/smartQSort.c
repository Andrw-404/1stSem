#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



void feedArray(int* array, int size) {
	for (int i = 0; i < size; ++i)
		array[i] = (rand() % 153) - 47;
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
	if (left > right)
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

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

bool sameness(int *firstArray, int *secondArray, int size) {
	for (int i = 0; i < size; ++i) {
		if (firstArray[i] != secondArray[i])
			return false;
	}
}

bool test() {
	int mainArray[45] = { 0 };
	int firstArray[45] = { 0 };
	int secondArray[45] = { 0 };
	int size = 45;

	feedArray(mainArray, size);
	memcpy(firstArray, mainArray, size);
	memcpy(secondArray, mainArray, size);
	
	qsort(firstArray, size, sizeof(int), compare);
	smartQSort(secondArray, 0, size - 1);
	
	if (!sameness(firstArray, secondArray, size))
		return false;
	
	return true;

}


int main(void) {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	if (!test()) {
		printf("!!!Ошибка. Тест не пройден!!!\n\n");
		return -1;
	}

	int array[60] = { 0 };
	int size = sizeof(array) / sizeof(array[0]);

	feedArray(array, size);
	
	int left = 0;
	int right = size - 1;

	printf("Изначальный массив:\n");

	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);

	smartQSort(array, left, right);

	printf("\n\nОтсортированный массив:\n");
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n\n\n");
}