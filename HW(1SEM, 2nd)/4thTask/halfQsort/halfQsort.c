#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


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
	int i =	0;
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
}

int main(void) {
	setlocale(LC_ALL, "Russian");
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