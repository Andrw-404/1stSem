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

bool testAdd() {
    List* list = createList();
    add(list, first(list), 10);
    if (isEmpty(list) || getValue(list, getNext(first(list))) != 10) {
        removeList(list);
        return false;
    }

    add(list, getNext(first(list)), 20);
    if (isEmpty(list) || getValue(list, getNext(first(list))) != 10
        || getValue(list, getPositionByNumber(list, 2)) != 20) {
        removeList(list);
        return false;
    }
    removeList(list);
    return true;
}

bool testGetValue() {
    List* list = createList();
    add(list, first(list), 10);
    add(list, getNext(first(list)), 20);

    Value testValue = getValue(list, getNext(first(list)));
    if (testValue != 10) {
        removeList(list);
        return false;
    }

    testValue = getValue(list, getPositionByNumber(list, 2));
    if (testValue != 20) {
        removeList(list);
        return false;
    }
    removeList(list);
    return true;
}

bool testSetValue() {
    List* list = createList();
    add(list, first(list), 10);
    add(list, getNext(first(list)), 20);

    setValue(list, getPositionByNumber(list, 1), 30);
    if (getValue(list, getPositionByNumber(list, 1)) != 30) {
        removeList(list);
        return false;
    }

    setValue(list, getPositionByNumber(list, 2), 40);
    if (getValue(list, getPositionByNumber(list, 2)) != 40) {
        removeList(list);
        return false;
    }
    removeList(list);
    return true;
}

bool testIsEmpty() {
    List* list = createList();
    if (!isEmpty(list)) {
        free(list);
        return false;
    }

    add(list, first(list), 10);
    if (isEmpty(list)) {
        removeList(list);
        return false;
    }
    if (isEmpty(list)) {
        removeList(list);
        return false;
    }
    removeList(list);
    return true;
}

bool testAddLast() {
    List* list = createList();
    addLast(list, 10);
    if (isEmpty(list) || getValue(list, getPositionByNumber(list, 1)) != 10) {
        removeList(list);
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
        testAdd(),
        testGetValue(),
        testSetValue(),
        testIsEmpty(),
        testAddLast()
    };
    for (int i = 1; i < 6; ++i) {
        if (!tests[i]) {
            printf("Test %d failed\n\n", i);
            return false;
        }
    }
    return true;
}