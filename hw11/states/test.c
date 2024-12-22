#include "states.h"
#include "readFromFile.h"

#include <stdlib.h>
#include <stdbool.h>

bool test() {
    int (*dist)[CITIES] = malloc(CITIES * sizeof * dist);
    int visited[100] = { 0 };
    int capitals[100];

    int n = 0;
    int m = 0;
    int k = 0;

    const char filename[100] = "testFile.txt";
    readFromFile(filename, &n, &m, &k, capitals, dist);
    State* arrayWithState[100];

    initializationOfStates(arrayWithState, capitals, visited, k);
    floydWarshall(n, dist);
    distributeCities(arrayWithState, n, dist, visited, k);

    if (getCapital(arrayWithState, 0) != 0 &&
        getCityCount(arrayWithState, 0) != 2 &&
        getCityByNumberInState(arrayWithState, 0, 0) != 0 &&
        getCityByNumberInState(arrayWithState, 0, 1) != 1) {
        clean(arrayWithState, k, dist);
        return false;
    }

    if (getCapital(arrayWithState, 1) != 3 &&
        getCityCount(arrayWithState, 1) != 2 &&
        getCityByNumberInState(arrayWithState, 1, 0) != 3 &&
        getCityByNumberInState(arrayWithState, 1, 1) != 2) {
        clean(arrayWithState, k, dist);
        return false;
    }

    if (getCapital(arrayWithState, 2) != 4 &&
        getCityCount(arrayWithState, 2) != 1 &&
        getCityByNumberInState(arrayWithState, 2, 0) != 4) {
        clean(arrayWithState, k, dist);
        return false;
    }

    if (getCapital(arrayWithState, 3) != 5 &&
        getCityCount(arrayWithState, 3) != 1 &&
        getCityByNumberInState(arrayWithState, 3, 0) != 5) {
        clean(arrayWithState, k, dist);
        return false;
    }

    clean(arrayWithState, k, dist);
    return true;
}