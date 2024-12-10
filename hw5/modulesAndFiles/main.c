#include "auxiliaryFunctions.h"
#include "sortingAndSearching.h"
#include "test.h"
#include "reader.h"

#include <locale.h>
#include <stdio.h>

int main(void) {
	setlocale(LC_ALL, "RUS");

	if (!test()) {
		printf("Ошибка. Тест не пройден\n\n");
		return -1;
	}

	int array[15] = { 0 };
	int length = 15;

	reader(array);

	printf("Массив: \n");
	printArray(array, length);
	printf("\n\n\n");


	printf("Наиболее часто встречающийся элемент в массиве: %d\n\n", frequentElement(array, length));
}