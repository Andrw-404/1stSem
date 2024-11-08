#pragma once

#include "list.h"

typedef enum {
    byName,
    byPhone
} SortType;

//splits the list into parts
void split(ListElement* source, ListElement** front, ListElement** back);

//sorts a list using a merge method
void mergeSort(ListElement** head, SortType sortType);

//combines two sorted lists into one, following the specified sort type
ListElement* merge(ListElement* first, ListElement* second, SortType sortType);
