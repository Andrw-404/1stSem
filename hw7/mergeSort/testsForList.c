#include "list.h"
#include "testsForList.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool testCreateList() {
    List* list = createList();
    return (list != NULL && isEmpty(list));
}

bool testIsEmpty() {
    List* list = createList();
    if (!isEmpty(list)) {
        return false;
    }

    addContact(list, "Andrew", "1111");
    if (isEmpty(list)) {
        return false;
    }

    return true;
}

bool testAddContact() {
    List* list = createList();
    addContact(list, "Andrew", "1111");
    addContact(list, "Boris", "2222");

    return !(isEmpty(list) || strcmp(list->head->name, "Boris") != 0 || strcmp(list->head->next->name, "Andrew") != 0);
}
