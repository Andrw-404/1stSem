#include "HashTable.h"
#include "test.h"

#include <stdio.h>

int main(void) {
    if (!runTests()) {
        return -1;
    }

    HashTable* table = createTable(135);
    const char filename[100] = "file.txt";
    readAndPrint(filename, table);
    
    printf("\n=============\nStatistics:\n");
    printf("Fill factor: %f \n", getFillFactor(table));
    printf("Average list length: %f \n", averageLength(table));
    printf("Maximum list length: %d \n", findingTheMaximumLength(table));
    removeTable(table);
}