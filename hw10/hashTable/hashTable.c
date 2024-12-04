#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    List* value;
} htItem;

typedef struct {
    int size;
    int number;
    List** buckets;
} hashTable;

hashTable* createTable(int size) {
    hashTable* table = malloc(sizeof(hashTable));
    if (table == NULL) {
        return NULL;
    }
    table->size = size;
    table->number = 0;
    table->buckets = malloc(size * sizeof(List*));
    if (table->buckets == NULL) {
        free(table);
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        table->buckets[i] = createList();
    }
    return table;
}

void deleteItem(htItem* item) {
    removeList(item->value);
    free(item);
}

void deleteTable(hashTable* table) {
    if (table == NULL) {
        return;
    }
    for (int i = 0; i < table->size; i++) {
        removeList(table->buckets[i]);
    }
    free(table->buckets);
    free(table);
}

int hash(char* key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); ++i) {
        hash = ((size * 2, 423) * key[i]) % size;
    }
    return hash;
}

void insert(hashTable* table, char* key) {
    if (table == NULL) {
        return;
    }
    int index = hash(key, table->size);

    List* bucket = table->buckets[index];
    ListElement* current = getFirst(bucket);
    while (current != NULL) {
        if (strcmp(getKey(current), key) == 0) {
            setCount(current, 1);
            return;
        }
        current = getNext(current);
    }
    addLast(bucket, key);
    table->number++;
}