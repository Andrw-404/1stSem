#include "list.h"
#include "mergeSort.h"
#include "test.h"

#include <stdbool.h>
#include <string.h>

bool testMergeSortByName() {
    List* testList = createList();
    addContact(testList, "Chris", "3333");
    addContact(testList, "Andrew", "1111");
    addContact(testList, "Boris", "2222");
    addContact(testList, "Dmitry", "4444");
    testList = mergeSort(testList, byName);

    const char* firstName = getName(getNext(getFirst(testList)));
    const char* secondName = getName(getNext(getNext(getFirst(testList))));
    const char* thirdName = getName(getNext(getNext(getNext(getFirst(testList)))));
    const char* fourthName = getName(getNext(getNext(getNext(getNext(getFirst(testList))))));

    if (strcmp(firstName, "Andrew") == 0 &&
        strcmp(secondName, "Boris") == 0 &&
        strcmp(thirdName, "Chris") == 0 &&
        strcmp(fourthName, "Dmitry") == 0) {
        removeList(&testList);
        return true;
    }
    removeList(&testList);
    return false;
}

bool testMergeSortByPhone() {
    List* testList = createList();
    addContact(testList, "Chris", "3333");
    addContact(testList, "Andrew", "1111");
    addContact(testList, "Boris", "2222");
    addContact(testList, "Dmitry", "4444");
    testList = mergeSort(testList, byPhone);

    const char* firstPhone = getPhone(getNext(getFirst(testList)));
    const char* secondPhone = getPhone(getNext(getNext(getFirst(testList))));
    const char* thirdPhone = getPhone(getNext(getNext(getNext(getFirst(testList)))));
    const char* fourthPhone = getPhone(getNext(getNext(getNext(getNext(getFirst(testList))))));

    if (strcmp(firstPhone, "1111") == 0 &&
        strcmp(secondPhone, "2222") == 0 &&
        strcmp(thirdPhone, "3333") == 0 &&
        strcmp(fourthPhone, "4444") == 0) {
        removeList(&testList);
        return true;
    }
    removeList(&testList);
    return false;
}