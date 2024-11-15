#include "sortedList.h"
#include "list.h"
#include "testsForTask.h"

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
    return (listForAddTest->head->next->value == -19 &&
        listForAddTest->head->next->next->value == -1 &&
        listForAddTest->head->next->next->next->value == 0 &&
        listForAddTest->head->next->next->next->next->value == 4 &&
        listForAddTest->head->next->next->next->next->next->value == 13 &&
        listForAddTest->head->next->next->next->next->next->next->value == 17);
}

bool testForRemove() {
    List* listForRemoveTest = createList();
    addElements(13, listForRemoveTest);
    addElements(17, listForRemoveTest);
    addElements(-1, listForRemoveTest);
    addElements(0, listForRemoveTest);
    addElements(-19, listForRemoveTest);
    addElements(4, listForRemoveTest);

    if (isEmpty(listForRemoveTest) || listForRemoveTest->head->next == NULL) {
        return false;
    }
    removeElement(13, listForRemoveTest);
    removeElement(17, listForRemoveTest);
    removeElement(-1, listForRemoveTest);
    removeElement(0, listForRemoveTest);
    removeElement(-19, listForRemoveTest);
    removeElement(4, listForRemoveTest);

    if (listForRemoveTest->head->next != NULL) {
        return false;
    }

    return isEmpty(listForRemoveTest);
}