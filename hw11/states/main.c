#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "test.h"
#include "states.h"
#include "readFromFile.h"

int main(void) {
    setlocale(LC_ALL, "RUS");
    if (!test()) {
        printf("\n\nTest failed!\n\n");
        return -1;
    }
    int (*dist)[CITIES] = malloc(CITIES * sizeof * dist);
    if (dist == NULL) {
        return -1;
    }

    int visited[100] = { 0 };
    int capitals[100];

    int n = 0;
    int m = 0;
    int k = 0;

    const char filename[100] = "file.txt";
    readFromFile(filename, &n, &m, &k, capitals, dist);
    State* arrayWithState[100];

    initializationOfStates(arrayWithState, capitals, visited, k);
    floydWarshall(n, dist);
    distributeCities(arrayWithState, n, dist, visited, k);
    printStates(arrayWithState, k);
    clean(arrayWithState, k, dist);
}