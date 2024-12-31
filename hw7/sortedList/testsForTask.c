#include "list.h"

#include <stdlib.h>
#include <stdbool.h>

bool testForAdd() {
    List* listForAddTest = createList();
    addElements(13, listForAddTest);
    addElements(17, listForAddTest);
    addElements(-1, listForAddTest);
    addElements(0, listForAddTest);
    addElements(-19, listForAddTest);
    addElements(4, listForAddTest);
    if (isEmpty(listForAddTest)) {
        return false;
    }
    if (getValue(listForAddTest, GetRealFirstElement(listForAddTest)) == -19 &&
        getValue(listForAddTest, getPositionByNumber(listForAddTest, 2)) == -1 &&
        getValue(listForAddTest, getPositionByNumber(listForAddTest, 3)) == 0 &&
        getValue(listForAddTest, getPositionByNumber(listForAddTest, 4)) == 4 &&
        getValue(listForAddTest, getPositionByNumber(listForAddTest, 5)) == 13 &&
        getValue(listForAddTest, getPositionByNumber(listForAddTest, 6)) == 17) {
        removeList(listForAddTest);
        return true;
    }
    removeList(listForAddTest);
    return false;
}

bool testForRemove() {
    List* listForRemoveTest = createList();
    addElements(13, listForRemoveTest);
    addElements(17, listForRemoveTest);
    addElements(-1, listForRemoveTest);
    addElements(0, listForRemoveTest);
    addElements(-19, listForRemoveTest);
    addElements(4, listForRemoveTest);

    if (isEmpty(listForRemoveTest) || GetRealFirstElement(listForRemoveTest) == NULL) {
        return false;
    }
    removeElement(13, listForRemoveTest);
    removeElement(17, listForRemoveTest);
    removeElement(-1, listForRemoveTest);
    removeElement(0, listForRemoveTest);
    removeElement(-19, listForRemoveTest);
    removeElement(4, listForRemoveTest);

    if (getNext(first(listForRemoveTest)) != NULL) {
        removeList(listForRemoveTest);
        return false;
    }
    if (isEmpty(listForRemoveTest)) {
        removeList(listForRemoveTest);
        return true;
    }
    else {
        removeList(listForRemoveTest);
        return false;
    }
}