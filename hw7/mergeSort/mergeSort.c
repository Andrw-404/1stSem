#include "list.h"
#include "mergeSort.h"

#include <string.h>

void split(ListElement* source, ListElement** front, ListElement** back) {
    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
        return;
    }
    ListElement* slow = source;
    ListElement* fast = source->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
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
        compare = strcmp(first->name, second->name);
    }
    else {
        compare = strcmp(first->phone, second->phone);
    }
    ListElement* result = 0;
    if (compare <= 0) {
        result = first;
        result->next = merge(first->next, second, sortType);
    }
    else {
        result = second;
        result->next = merge(first, second->next, sortType);
    }
    return result;
}

void mergeSort(ListElement** head, SortType sortType) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    ListElement* first = 0;
    ListElement* second = 0;
    split(*head, &first, &second);

    mergeSort(&first, sortType);
    mergeSort(&second, sortType);
    *head = merge(first, second, sortType);
}