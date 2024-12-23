#include "list.h"
#include "stdio.h"
#include "list.h"

int main(void) {
    List* list = createList();
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 4);
    addLast(list, 5);
    printList(list);
    removeOddIndexedElements(list);
    printList(list);
    removeList(list);
}