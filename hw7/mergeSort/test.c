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

    List* first = NULL;
    List* second = NULL;
    split(testList, &first, &second);

    char* firstName = getName(getNext(getFirst(first)));
    char* secondName = getName(getNext(getNext(getFirst(first))));

    char* thirdName = getName(getNext(getFirst(second)));
    char* fourthName = getName(getNext(getNext(getFirst(second))));

    if (strcmp(firstName, "Chris") == 0 &&
        strcmp(secondName, "Dmitry") == 0 &&
        strcmp(thirdName, "Andrew") == 0 &&
        strcmp(fourthName, "Boris") == 0) {
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
    addContact(testList, "Dmitry", "4444");
    testList = mergeSort(testList, byName);

    char* firstName = getName(getNext(getFirst(testList)));
    char* secondName = getName(getNext(getNext(getFirst(testList))));
    char* thirdName = getName(getNext(getNext(getNext(getFirst(testList)))));
    char* fourthName = getName(getNext(getNext(getNext(getNext(getFirst(testList))))));

    if (strcmp(firstName, "Andrew") == 0 &&
        strcmp(secondName, "Boris") == 0 &&
        strcmp(thirdName, "Chris") == 0 &&
        strcmp(fourthName, "Dmitry") == 0) {
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
    addContact(testList, "Dmitry", "4444");
    testList = mergeSort(testList, byPhone);

    char* firstPhone = getPhone(getNext(getFirst(testList)));
    char* secondPhone = getPhone(getNext(getNext(getFirst(testList))));
    char* thirdPhone = getPhone(getNext(getNext(getNext(getFirst(testList)))));
    char* fourthPhone = getPhone(getNext(getNext(getNext(getNext(getFirst(testList))))));

    if (strcmp(firstPhone, "1111") == 0 &&
        strcmp(secondPhone, "2222") == 0 &&
        strcmp(thirdPhone, "3333") == 0 &&
        strcmp(fourthPhone, "4444") == 0) {
        removeList(testList);
        return true;
    }
    removeList(testList);
    return false;
}