#include "list.h"
#include "testsForList.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


bool testCreateList() {
    List* list = createList();
    if (list != NULL && isEmpty(list)) {
        removeList(list);
        return true;
    }
    removeList(list);
    return false;
}

bool testGetValue() {
    List* list = createList();
    addElements(10, list);
    addElements(30, list);

    Value testValue = getValue(list, getNext(first(list)));
    if (testValue != 10) {
        removeList(list);
        return false;
    }

    if (30 == getValue(list, getPositionByNumber(list, 2))) {
        removeList(list);
        return true;
    }
    removeList(list);
    return false;
}

bool testSetValue() {
    List* list = createList();
    addElements(10, list);
    addElements(30, list);

    setValue(list, getPositionByNumber(list, 1), 30);
    if (getValue(list, getPositionByNumber(list, 1)) != 30) {
        removeList(list);
        return false;
    }

    setValue(list, getPositionByNumber(list, 2), 40);
    if (getValue(list, getPositionByNumber(list, 2)) == 40) {
        removeList(list);
        return true;
    }
    removeList(list);
    return false;
}

bool testIsLast() {
    List* list = createList();
    addElements(10, list);
    addElements(30, list);

    if (!isLast(list, getPositionByNumber(list, 2))) {
        removeList(list);
        return false;
    }

    if (!isLast(list, getNext(first(list)))) {
        removeList(list);
        return true;
    }
    removeList(list);
    return false;
}

bool testIsEmpty() {
    List* list = createList();
    if (!isEmpty(list)) {
        removeList(list);
        return false;
    }

    addElements(10, list);
    if (isEmpty(list)) {
        removeList(list);
        return false;
    }
    if (!isEmpty(list)) {
        removeList(list);
        return true;
    }
    removeList(list);
    return false;
}

bool testAddLast() {
    List* list = createList();
    addLast(list, 10);
    if (isEmpty(list) || getValue(list, getPositionByNumber(list, 1)) != 10) {
        return false;
    }

    addLast(list, 20);
    if (isEmpty(list) || getValue(list, getPositionByNumber(list, 2)) != 20) {
        removeList(list);
        return false;
    }
    removeList(list);
    return true;
}

bool runTests() {
    bool tests[] = {
        testCreateList(),
        testGetValue(),
        testSetValue(),
        testIsLast(),
        testIsEmpty(),
        testAddLast(),
    };
    for (int i = 1; i < 6; ++i) {
        if (!tests[i]) {
            printf("Test %d failed\n\n", i);
            return false;
        }
    }
    return true;
}