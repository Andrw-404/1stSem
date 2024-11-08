#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include "reader.h"
#include "mergeSort.h"
#include "test.h"
#include "testsForList.h"

#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Rus");
    SortType sortType;
    if (!testCreateList() || !testIsEmpty() || !testAddContact()) {
        printf("!!!the list did not pass the tests!!!\n\n\n");
        return NULL;
    }

    if (!testSplit() || !testMergeByName() || !testMergeByPhone() || !testMergeSortByName()|| !testMergeSortByPhone()) {
        printf("!!!the program failed the tests!!!\n\n\n");
        return NULL;
    }

    List* list = createList();
    reader("contacts.txt", list);
    printList(list);
    int choice = 0;
    printf("Сортировать по: Имени(1) или Телефону(2)\n");
    scanf("%d", &choice);

    if (choice == 1) {
        sortType = byName;
    }
    else if (choice == 2) {
        sortType = byPhone;
    }
    else {
        printf("Ошибка ввода\n");
        removeList(list);
        return 1;
    }

    mergeSort(&list->head, sortType);
    printf("\nОтсортированный список: \n\n\n");
    printList(list);
    removeList(list);
}