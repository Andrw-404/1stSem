#pragma once

#include <stdbool.h>

//checks whether the list is divided into parts correctly
bool testSplit();

//checks the correctness of the merge function when sorting by name
bool testMergeByName();

//checks the correctness of the merge function when sorting by phone number
bool testMergeByPhone();

//checks that the mergeSort function is correct when sorting by name
bool testMergeSortByName();

//checks that the mergeSort function is correct when sorting by phone number
bool testMergeSortByPhone();