#include "list.h"
#include "mergeSort.h"

#include <string.h>

void split(ListElement* source, ListElement** front, ListElement** back) {
    if (source == NULL || getNext(source) == NULL) {
        *front = source;
        *back = NULL;
        return;
    }
    ListElement* slow = source;
    ListElement* fast = getNext(source);
    
    while (fast != NULL && getNext(fast) != NULL) {
        fast = getNext(getNext(fast));
        slow = getNext(slow);
    }
    *front = source;
    *back = getNext(slow);
    setNext(slow, NULL);
}

ListElement* merge(ListElement* first, ListElement* second, SortType sortType) {
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }
    int compare = 0;
    if (sortType == byName) {
        compare = strcmp(getName(first), getName(second));
    }
    else {
        compare = strcmp(getPhone(first), getPhone(second));
    }
    ListElement* result = 0;
    if (compare <= 0) {
        result = first;
        setNext(result, merge(getNext(first), second, sortType));
    }
    else {
        result = second;
        setNext(result, merge(first, getNext(second), sortType));

    }
    return result;
}

void mergeSort(ListElement** head, SortType sortType) {
    if (*head == NULL || getNext(*head) == NULL) {
        return;
    }
    ListElement* first = 0;
    ListElement* second = 0;
    split(*head, getDoublePointer(first), getDoublePointer(second));

    mergeSort(&first, sortType);
    mergeSort(&second, sortType);
    *head = merge(first, second, sortType);
}