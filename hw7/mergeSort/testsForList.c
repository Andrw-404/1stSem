#include "list.h"
#include "testsForList.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool testCreateList() {
    List* list = createList();
    return (list != NULL && isEmpty(list));
}

bool testIsEmpty() {
    List* list = createList();
    if (!isEmpty(list)) {
        return false;
    }

    addContact(list, "Andrew", "1111");
    if (isEmpty(list)) {
        return false;
    }

    return true;
}

bool testAddContact() {
    List* testList = createList();
    addContact(testList, "Andrew", "1111");
    addContact(testList, "Boris", "2222");

    return !(isEmpty(testList) || strcmp(getName(getFirst(testList)),"Boris") != 0 || strcmp(getName(getNext(getFirst(testList))), "Andrew") != 0);
}
