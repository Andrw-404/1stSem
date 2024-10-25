#include "reader.h"

#include <stdio.h>

int reader(int* array) {
	unsigned int readingLength = 0;
	FILE* file = fopen("elementsForTask.txt", "r");
	if (file == NULL) {
		perror("elementsForTask.txt");
		return -1;
	}
	while (fscanf_s(file, "%d; ", &array[readingLength]) == 1) {
		readingLength++;
	}
	return *array;

	fclose(file);
}

int readerForTest(int* array) {
	unsigned int readingLengthForTest = 0;
	FILE* testFile = fopen("elementsForTest.txt", "r");
	if (testFile == NULL) {
		perror("elementsForTest.txt");
		return -1;
	}
	while (fscanf_s(testFile, "%d; ", &array[readingLengthForTest]) == 1) {
		readingLengthForTest++;
	}
	return *array;

	fclose(testFile);
}

