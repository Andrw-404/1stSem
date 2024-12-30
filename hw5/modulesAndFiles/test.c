#include "test.h"
#include "reader.h"
#include "sortingAndSearching.h"
#include <stdbool.h>

bool test() {
	int testArray[9] = { 0 };
	readerForTest(testArray);
	int desired = 1;
	return (frequentElement(testArray, 9) == desired);
}