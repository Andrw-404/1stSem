#include <stdbool.h>
#include <stdlib.h>

#include "directedGraph.h"
#include "readFromFile.h"

bool test() {
    int (*testDist)[CITIES] = malloc(CITIES * sizeof * testDist);
    if (testDist == NULL) {
        return -1;
    }

    int visited[CITIES] = { 0 };
    bool reachEveryone[CITIES];
    int n = 0;

    const char filename[100] = "testFile.txt";
    readFromFile(filename, testDist, &n);

    find(testDist, n, reachEveryone);
    for (int i = 0; i < 6; ++i) {
        if (reachEveryone[1]) {
            free(testDist);
            return true;
        }
    }
    free(testDist);
    return true;
}