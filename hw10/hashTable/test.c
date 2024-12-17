#include "hashTable.h"
#include "test.h"

#include <stdbool.h>
#include <stdio.h>

bool testForInsert() {
    HashTable* testTable = createTable(5);
    insert(testTable, "aaa");
    insert(testTable, "bbb");
    insert(testTable, "ccc");
    insert(testTable, "ddd");
    insert(testTable, "eee");
    if (searchInBuckets(testTable, "aaa") && 
        searchInBuckets(testTable, "bbb") && 
        searchInBuckets(testTable, "ccc") && 
        searchInBuckets(testTable, "ddd") && 
        searchInBuckets(testTable, "eee")) {
        removeTable(testTable);
        return true;
    }
    removeTable(testTable);
    return false;
}

bool runTests() {
    bool tests[1] = { testForInsert() };
    for (int i = 0; i < 1; ++i) {
        if (!tests[i]) {
            printf("Test %d is failed\n\n", i);
            return false;
        }
    }
    return true;
}
