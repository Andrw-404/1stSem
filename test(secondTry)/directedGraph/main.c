#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "test.h"
#include "states.h"
#include "readFromFile.h"

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!test()) {
        printf("Test failed\n\n");
        return -111;
    }

    int (*dist)[CITIES] = malloc(CITIES * sizeof * dist);
    if (dist == NULL) {
        return -1;
    }

    int visited[100] = { 0 };
    bool reachEveryone[CITIES];
    int n = 0;

    const char filename[100] = "file.txt";
    readFromFile(filename, dist, &n);

    find(dist, n, reachEveryone);
    printReachableNodes(n, reachEveryone);
    free(dist);
}