#define _CRT_SECURE_NO_WARNINGS
#include "hashTableOnArray.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    size_t size;
    char** buckets;
    size_t number;
} HashTable;

HashTable* createTable(size_t size, int* errorCode) {
    HashTable* table = malloc(sizeof(HashTable));
    if (table == NULL) {
        *errorCode = -5;
        return NULL;
    }
    table->size = size;
    table->buckets = malloc(size * sizeof(char*));
    if (table->buckets == NULL) {
        free(table);
        return NULL;
    }
    return table;
}

int hash(char* key, size_t size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); ++i) {
        hash = ((hash * 31) * 101 + key[i]) % size;
    }
    return hash;
}

void insert(HashTable* table, char* key, int *errorCode) {
    if (table == NULL) {
        *errorCode = -1;
        return;
    }
    size_t index = hash(key, table->size);
    size_t index2 = index;
    while (table->buckets[index] != NULL && strcmp(table->buckets[index], key) == 0) {
        index = (index + 1) & table->size;
        if (index == index2) {
            *errorCode = -3;
            return;
        }
    }
    char* newString = malloc(sizeof(char));
    if (newString == NULL) {
        *errorCode = -5;
        return;
    }
    strcpy(newString, key);
    table->buckets[index] = newString;
    table->number++;
    if (table->buckets[index] == NULL) {
        *errorCode = -1;
        return;
    }
}

void removeTable(HashTable* table, int* errorCode) {
    if (table == NULL) {
        *errorCode = -1;
        return;
    }
    for (int i = 0; i < table->size; ++i) {
        if (table->buckets[i] != NULL) {
            free(table->buckets[i]);
        }
    }
    free(table->buckets);
    free(table);
}

bool searchInBuckets(HashTable* table, char* key, int* errorCode) {
    if (table == NULL) {
        printf("Table is NULL\n");
        *errorCode = -1;
        return false;
    }
    size_t index = 0;
    size_t hashIndex = hash(key, table->size);
    while (table->buckets[hashIndex] != NULL) {
        if (strcmp(table->buckets[hashIndex], key) == 0) {
            return true;
        }
        hashIndex = (hashIndex + 1) % table->size;
        if (hashIndex == index) {
            break;
        }
    }
    return false;
}