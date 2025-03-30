#include "list.h"
#include "testsForList.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


bool testCreateList() {
    List* list = createList();
    return (list != NULL && isEmpty(list));
}

bool testAdd() {
    List* list = createList();
    add(list, first(list), 10);
    if (isEmpty(list) || getValue(list, getNext(first(list))) != 10) {
        return false;
    }

    add(list, getNext(first(list)), 20);
    return !(isEmpty(list) || getValue(list, getNext(first(list))) != 10
        || getValue(list, getPositionByNumber(list, 2)) != 20);
}

bool testGetValue() {
    List* list = createList();
    add(list, first(list), 10);
    add(list, getNext(first(list)), 20);

    Value testValue = getValue(list, getNext(first(list)));
    if (testValue != 10) {
        return false;
    }

    testValue = getValue(list, getPositionByNumber(list, 2));
    return testValue == 20;
}

bool testSetValue() {
    List* list = createList();
    add(list, first(list), 10);
    add(list, getNext(first(list)), 20);

    setValue(list, getPositionByNumber(list, 1), 30);
    if (getValue(list, getPositionByNumber(list, 1)) != 30) {
        return false;
    }

    setValue(list, getPositionByNumber(list, 2), 40);
    return getValue(list, getPositionByNumber(list, 2)) == 40;
}

bool testIsLast() {
    List* list = createList();
    add(list, first(list), 10);
    add(list, getNext(first(list)), 20);

    if (!isLast(list, getPositionByNumber(list, 2))) {
        return false;
    }

    return !isLast(list, getNext(first(list)));
}

bool testIsEmpty() {
    List* list = createList();
    if (!isEmpty(list)) {
        return false;
    }

    add(list, first(list), 10);
    if (isEmpty(list)) {
        return false;
    }
    return !isEmpty(list);
}

bool testAddLast() {
    List* list = createList();
    addLast(list, 10);
    if (isEmpty(list) || getValue(list, getPositionByNumber(list, 1)) != 10) {
        return false;
    }

    addLast(list, 20);
    return !(isEmpty(list) || getValue(list, getPositionByNumber(list, 2)) != 20);
}

bool testMakeACircularList() {
    List* list = createList();
    addLast(list, 10);
    addLast(list, 30);
    addLast(list, 50);
    if (isEmpty(list) || getValue(list, getNext(first(list))) != 10 ||
        getValue(list, getPositionByNumber(list, 2)) != 30 ||
        getValue(list, getPositionByNumber(list, 3)) != 50) {
        return false;
    }
    if (getPositionByNumber(list, 4) != NULL) {
        return false;
    }
    makeACircularList(list);
    return (getNext(getPositionByNumber(list, 3)) == getNext(first(list)));
}

bool testForRemoveOddElements() {
    List* list = createList();
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 4);
    addLast(list, 5);
    if (isEmpty(list) || getValue(list, getPositionByNumber(list, 1)) != 10) {
        removeList(list);
        return false;
    }

    removeOddIndexedElements(list);
    if (getValue(list, first(list)) != 1 || getValue(list, getPositionByNumber(list, 2)) != 3 || getValue(list, getPositionByNumber(list, 3)) != 5) {
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
        testIsLast(),
        testIsEmpty(),
        testAddLast(),
        testMakeACircularList(),
        testForRemoveOddElements()
    };
    for (int i = 1; i < 9; ++i) {
        if (!tests[i]) {
            printf("Test %d failed\n\n", i);
            return false;
        }
    }
    return true;
}

