#pragma once

#include "list.h"

typedef enum {
    byName,
    byPhone
} SortType;

// splits the list into parts
void split(List* source, List** front, List** back);

// sorts a list using a merge method
List* mergeSort(List* list, SortType sortType);

// combines two sorted lists into one, following the specified sort type
List* merge(List* first, List* second, SortType sortType);