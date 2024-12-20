#include <stdio.h>
#include "hashTableOnArray.h"
#include "test.h"

int main(void) {
    int* errorCode = 0;
    if (!test()) {
        printf("Test is failed");
        return;
    }
    HashTable* table = createTable(3, errorCode);
    insert(table, "qwe", errorCode);
    insert(table, "qdas", errorCode);
    insert(table, "hhh", errorCode);
}