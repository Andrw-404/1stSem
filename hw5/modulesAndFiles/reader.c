#include "reader.h"

#include <stdio.h>

int reader(int* array) {
	unsigned int lengthRead = 0;
	FILE* file = fopen("elementsForTask.txt", "r");
	if (file == NULL) {
		perror("elementsForTask.txt");
		return -1;
	}
	while (fscanf_s(file, "%d; ", &array[lengthRead]) == 1) {
		lengthRead++;
	}
	return *array;

	fclose(file);
}
