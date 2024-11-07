#include "list.h"
#include "testsForList.h"

#include <stdio.h>

int main(void) {
    if (!testAdd() || !testAddLast() || !testCreateList() || !testGetValue()
        || !testIsEmpty() || !testIsLast() || !testSetValue()) {
        printf("!!!the list did not pass the tests!!!\n\n\n");
        return NULL;
    }
    List* list = createList();
    addLast(list, 10);
    addLast(list, 30);
    addLast(list, 50);
    printList(list);
    setValue(list, list->head->next->next, 432);
    printList(list);
}