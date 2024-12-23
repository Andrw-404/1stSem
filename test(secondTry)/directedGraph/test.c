#include <stdbool.h>
#include <stdlib.h>

#include "states.h"
#include "readFromFile.h"

bool test() {
    int (*testDist)[CITIES] = malloc(CITIES * sizeof * testDist);
    if (testDist == NULL) {
        return -1;
    }

    int visited[100] = { 0 };
    bool reachEveryone[CITIES];
    int n = 0;

    const char filename[100] = "testFile.txt";
    readFromFile(filename, testDist, &n);

    find(testDist, n, reachEveryone);
    for (int i = 0; i < 6; ++i) {
        if (!reachEveryone[i]) {
            free(testDist);
            return false;
        }
    }
    free(testDist);
    return true;
}