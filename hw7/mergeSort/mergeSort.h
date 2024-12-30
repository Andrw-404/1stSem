#pragma once

#include "list.h"

typedef enum {
    byName,
    byPhone
} SortType;

// sorts a list using a merge method
List* mergeSort(List* list, SortType sortType);
