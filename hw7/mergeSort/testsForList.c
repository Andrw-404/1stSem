#include "list.h"
#include "testsForList.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool testCreateList() {
    List* list = createList();
    if (list == NULL) {
        removeList(list);
        return false;
    }
    removeList(list);
    return true;
}

bool testIsEmpty() {
    List* list = createList();
    if (!isEmpty(list)) {
        removeList(list);
        return false;
    }

    addContact(list, "Andrew", "1111");
    if (isEmpty(list)) {
        removeList(list);
        return false;
    }
    removeList(list);
    return true;
}

bool testAddContact() {
    List* testList = createList();
    addContact(testList, "Andrew", "1111");
    addContact(testList, "Boris", "2222");

    if (isEmpty(testList) || strcmp(getName(getNext(getFirst(testList))), "Boris") != 0 ||
        strcmp(getName(getNext(getNext(getFirst(testList)))), "Andrew") != 0) {
        removeList(testList);
        return false;
    }
    removeList(testList);
    return true;
}
