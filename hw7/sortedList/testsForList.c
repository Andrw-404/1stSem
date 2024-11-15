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
    add(list, list->head, 10);
    if (isEmpty(list) || list->head->next->value != 10) {
        return false;
    }

    add(list, list->head->next, 20);
    return !(isEmpty(list) || list->head->next->value != 10 || list->head->next->next->value != 20);
}

bool testGetValue() {
    List* list = createList();
    add(list, list->head, 10);
    add(list, list->head->next, 20);

    Value testValue = getValue(list, list->head->next);
    if (testValue != 10) {
        return false;
    }

    testValue = getValue(list, list->head->next->next);
    return testValue == 20;
}

bool testSetValue() {
    List* list = createList();
    add(list, list->head, 10);
    add(list, list->head->next, 20);

    setValue(list, list->head->next, 30);
    if (getValue(list, list->head->next) != 30) {
        return false;
    }

    setValue(list, list->head->next->next, 40);
    return getValue(list, list->head->next->next) == 40;
}

bool testIsLast() {
    List* list = createList();
    add(list, list->head, 10);
    add(list, list->head->next, 20);

    if (!isLast(list, list->head->next->next)) {
        return false;
    }

    return !isLast(list, list->head->next);
}

bool testIsEmpty() {
    List* list = createList();
    if (!isEmpty(list)) {
        return false;
    }

    add(list, list->head, 10);
    if (isEmpty(list)) {
        return false;
    }
    return !isEmpty(list);
}

bool testAddLast() {
    List* list = createList();
    addLast(list, 10);
    if (isEmpty(list) || list->head->next->value != 10) {
        return false;
    }

    addLast(list, 20);
    return !(isEmpty(list) || list->head->next->next->value != 20);
}

bool testMakeACircularList() {
    List* list = createList();
    addLast(list, 10);
    addLast(list, 30);
    addLast(list, 50);
    if (isEmpty(list) || list->head->next->value != 10 || list->head->next->next->value != 30 || list->head->next->next->next->value != 50) {
        return false;
    }
    if (list->head->next->next->next->next != NULL) {
        return false;
    }
    makeACircularList(list);
    return (list->head->next->next->next->next->value == 10);
}