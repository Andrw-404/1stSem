#include "test.h"

#include <stdbool.h>

bool test() {
	int testArray[9] = { 1, 3, 4, 6, 1, 2, 5, 9, 1 };
	int desired = 1;
	return (frequentElement(testArray, 9) == desired);
}