#include "list.h"
#include "mergeSort.h"
#include "test.h"

#include <stdbool.h>
#include <string.h>

bool testSplit() {
    ListElement firstElement = { "Andrew", "1111", NULL };
    ListElement secondElement = { "Boris", "2222", NULL };
    ListElement thirdElement = { "Chris", "3333", NULL };
    ListElement fourthElement = { "Dmitry", "4444", NULL };

    firstElement.next = &secondElement;
    secondElement.next = &thirdElement;
    thirdElement.next = &fourthElement;


    ListElement* first = NULL;
    ListElement* second = NULL;
    split(&firstElement, &first, &second);

    return first == &firstElement && first->next == &secondElement && second == &thirdElement && second->next == &fourthElement;
}

bool testMergeByName() {
    ListElement firstElem = { "Andrew", "1111", NULL };
    ListElement secondElem = { "Boris", "2222", NULL };
    ListElement* result = merge(&firstElem, &secondElem, byName);

    return result == &firstElem && result->next == &secondElem && result->next->next == NULL;
}

bool testMergeByPhone() {
    ListElement firstElem = { "Andrew", "1111", NULL };
    ListElement secondElem = { "Boris", "2222", NULL };
    ListElement* result = merge(&firstElem, &secondElem, byPhone);

    return result == &firstElem && result->next == &secondElem && result->next->next == NULL;
}

bool testMergeSortByName() {
    List* list = createList();
    addContact(list, "Chris", "3333");
    addContact(list, "Andrew", "1111");
    addContact(list, "Boris", "2222");
    mergeSort(&list->head, byName);

    return strcmp(list->head->next->name, "Andrew") == 0 &&
        strcmp(list->head->next->next->name, "Boris") == 0 &&
        strcmp(list->head->next->next->next->name, "Chris") == 0;
}

bool testMergeSortByPhone() {
    List* list = createList();
    addContact(list, "Chris", "3333");
    addContact(list, "Andrew", "1111");
    addContact(list, "Boris", "2222");
    mergeSort(&list->head, byPhone);

    return strcmp(list->head->next->phone, "1111") == 0 &&
        strcmp(list->head->next->next->phone, "2222") == 0 &&
        strcmp(list->head->next->next->next->phone, "3333") == 0;
}
