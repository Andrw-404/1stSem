#include "hashTable.h"

#include <stdio.h>

int main(void) {
    hashTable* table = createTable(14);
    insert(table, "mama ");
}