#include "list.h"
#include "testsForList.h"

#include <stdio.h>

int main(void) {
    if (!runTests()) {
        return NULL;
    }
    List* list = createList();
    addLast(list, 10);
    addLast(list, 30);
    addLast(list, 50);
    printList(list);
    setValue(list, getPositionByNumber(list, 3), 432);
    printList(list);
    addLast(list, 65);
    makeACircularList(list);
    removeElement(list, getPositionByNumber(list, 1));
}