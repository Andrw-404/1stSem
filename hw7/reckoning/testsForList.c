#include "list.h"
#include "testsForList.h"

#include <stdbool.h>
#include <stdlib.h>

bool createCircularListTest() {
    ListElement* testElement = createListElement(6);
    if (getNumber(testElement) != 6) {
        free(testElement);
        return false;
    }
    free(testElement);
    ListElement* head = createCircularList(3);
    if (head == NULL ||
        getNumber(head) != 1 ||
        getNumber(getNext(head)) != 2 ||
        getNumber(getNext(getNext(head))) != 3 ||
        getNumber(getNext(getNext(getNext(head)))) != 1) {

        deleteCircularList(head);
        return false;
    }
    deleteCircularList(head);
    return true;
}