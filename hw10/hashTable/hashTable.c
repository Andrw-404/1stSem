#include "hashTable.h"
#include "list.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    int size;
    int number;
    List** buckets;
} HashTable;

HashTable* createTable(int size) {
    HashTable* table = malloc(sizeof(HashTable));
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

int hash(char* key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); ++i) {
        hash = ((hash * 31) * 101 + key[i]) % size;
    }
    return hash;
}

void insert(HashTable* table, char* key) {
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

double getFillFactor(HashTable* table) {
    if (table == NULL) {
        return 0;
    }
    if (table->number == 0) {
        printf("HashTable is empty :( ");
        return 0;
    }
    double res = (double)table->number / (double)table->size;
    return res;
}

int getNumberOfNonEmptyLists(HashTable* table) {
    if (table == NULL) {
        return 0;
    }
    int numOfNon = 0;
    for (int i = 0; i < table->size; ++i) {
        if (getFirst(table->buckets[i]) != NULL) {
            ++numOfNon;
        }
    }
    return numOfNon;
}

float averageLength(HashTable* table) {
    if (table == NULL) {
        return 0;
    }
    int lengthOfNonEmptyLists = 0;
    int NonEmptyLists = getNumberOfNonEmptyLists(table);
    for (int i = 0; i < table->size; ++i) {
        lengthOfNonEmptyLists += getListLength(table->buckets[i]);
    }
    return (float)lengthOfNonEmptyLists / (float)NonEmptyLists;
}

int findingTheMaximumLength(HashTable* table) {
    int max = 0;
    for (int i = 0; i < table->size; ++i) {
        int tmp = getListLength(table->buckets[i]);
        if (max < tmp) {
            max = tmp;
        }
    }
    return max;
}

void cleanWord(char* word) {
    int index = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (isalnum(word[i])) {
            word[index] = word[i];
            index++;
        }
    }
    word[index] = '\0';
}

void readAndPrint(const char* filename, HashTable* table) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }
    char word[256] = "";
    while (fscanf(file, "%255s", word) == 1) {
        cleanWord(word);
        insert(table, word);
    }
    fclose(file);
    printf("=============\nWord frequency: \n");
    for (int i = 0; i < table->size; ++i) {
        List* bucket = table->buckets[i];
        ListElement* element = getFirst(bucket);
        while (element != NULL) {
            printf("%s : %d \n", getKey(element), getCount(element));
            element = getNext(element);
        }
    }
}

void removeTable(HashTable* table) {
    if (table == NULL) {
        return;
    }
    for (int i = 0; i < table->size; ++i) {
        if (table->buckets[i] != NULL) {
            removeList(table->buckets[i]);
        }
    }
    free(table->buckets);
    free(table);
}

bool searchInBuckets(HashTable* table, const char* key) {
    if (table == NULL) {
        printf("Table is NULL\n");
        return false;
    }
    for (int i = 0; i < table->size; ++i) {
        ListElement* current = getFirst(table->buckets[i]);
        while (current != NULL) {
            if (strcmp(key, getKey(current)) == 0) {
                return true;
            }
            current = getNext(current);
        }
    }
    return false;
}