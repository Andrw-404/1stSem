#include "list.h"
#include "mergeSort.h"

#include <string.h>

void split(List* source, List** front, List** back) {
    *front = createList();
    *back = createList();

    ListElement* pos = getNext(getFirst(source));

    int length = 0;
    while (pos != NULL) {
        ++length;
        pos = getNext(pos);
    }

    pos = getNext(getFirst(source));

    for (int i = 0; i < length / 2; ++i) {
        addContact(*front, getName(pos), getPhone(pos));
        pos = getNext(pos);
    }

    while (pos != NULL) {
        addContact(*back, getName(pos), getPhone(pos));
        pos = getNext(pos);
    }
}

List* merge(List* first, List* second, SortType sortType) {
    List* mergedList = createList();
    ListElement* current = getFirst(mergedList);

    ListElement* firstElement = getNext(getFirst(first));
    ListElement* secondElement = getNext(getFirst(second));

    while (firstElement != NULL && secondElement != NULL) {
        int compare = (sortType == byName) ?
            strcmp(getName(firstElement), getName(secondElement)) :
            strcmp(getPhone(firstElement), getPhone(secondElement));

        if (compare <= 0) {
            setNext(current, firstElement);
            current = firstElement;
            firstElement = getNext(firstElement);
        }
        else {
            setNext(current, secondElement);
            current = secondElement;
            secondElement = getNext(secondElement);
        }
    }

    if (firstElement != NULL) {
        setNext(current, firstElement);
    }
    else {
        setNext(current, secondElement);
    }
    return mergedList;
}

List* mergeSort(List* list, SortType sortType) {
    if (isEmpty(list) || getNext(getNext(getFirst(list))) == NULL) {
        return list;
    }

    List* first = NULL;
    List* second = NULL;
    split(list, &first, &second);

    first = mergeSort(first, sortType);
    second = mergeSort(second, sortType);
    return merge(first, second, sortType);
}
