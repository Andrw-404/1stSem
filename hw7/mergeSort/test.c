#include "list.h"
#include "mergeSort.h"
#include "test.h"

#include <stdbool.h>
#include <string.h>

bool testSplit() {
    List* testList = createList();
    addContact(testList, "Andrew", "1111");
    addContact(testList, "Boris", "2222");
    addContact(testList, "Chris", "3333");
    addContact(testList, "Dmitry", "4444");

    ListElement* first = NULL;
    ListElement* second = NULL;
    split(getFirst(testList), &first, &second);

    char* firstName = getName(getFirst(testList));
    char* secondName = getName(getNext(getFirst(testList)));
    if (strcmp(getName(first), "Dmitry") == 0 &&
        strcmp(getName(getNext(getFirst(testList))), "Chris") == 0 &&
        strcmp(getName(getNext(getNext(first))), "Boris") == 0 &&
        strcmp(getName(second), "Andrew") == 0) {
        removeList(testList);
        return true;
    }
    removeList(testList);
    return false;
}

bool testMergeSortByName() {
    List* testList = createList();
    addContact(testList, "Chris", "3333");
    addContact(testList, "Andrew", "1111");
    addContact(testList, "Boris", "2222");
    mergeSort(getDoublePointer(getFirst(testList)), byName);

    if (strcmp(getName(getFirst(testList)), "Andrew") == 0 &&
        strcmp(getName(getNext(getFirst(testList))), "Boris") == 0 &&
        strcmp(getName(getNext(getNext(getFirst(testList)))), "Chris") == 0) {
        removeList(testList);
        return true;
    }
    removeList(testList);
    return false;
}

bool testMergeSortByPhone() {
    List* testList = createList();
    addContact(testList, "Chris", "3333");
    addContact(testList, "Andrew", "1111");
    addContact(testList, "Boris", "2222");
    mergeSort(getDoublePointer(getFirst(testList)), byName);

    if (strcmp(getName(getFirst(testList)), "1111") == 0 &&
        strcmp(getName(getNext(getFirst(testList))), "2222") == 0 &&
        strcmp(getName(getNext(getNext(getFirst(testList)))), "3333") == 0) {
        removeList(testList);
        return true;
    }
    removeList(testList);
    return false;
}
