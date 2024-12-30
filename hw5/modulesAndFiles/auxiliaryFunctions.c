#include "auxiliaryFunctions.h"

#include <stdio.h>
#include <string.h>


void printArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
}