#include "hashTableOnArray.h"
#include <stdbool.h>
#include "test.h"

bool test() {
    int* testErrorCode = 0;
    HashTable* testTable = createTable(5, testErrorCode);
    insert(testTable, "aaa", testErrorCode);
    insert(testTable, "bbb", testErrorCode);
    insert(testTable, "ccc", testErrorCode);
    insert(testTable, "ddd", testErrorCode);
    insert(testTable, "eee", testErrorCode);
    if (searchInBuckets(testTable, "aaa", testErrorCode) &&
        searchInBuckets(testTable, "bbb", testErrorCode) &&
        searchInBuckets(testTable, "ccc", testErrorCode) &&
        searchInBuckets(testTable, "ddd", testErrorCode) &&
        searchInBuckets(testTable, "eee", testErrorCode)) {
        removeTable(testTable, testErrorCode);
        return true;
    }
    removeTable(testTable, testErrorCode);
    return false;
}