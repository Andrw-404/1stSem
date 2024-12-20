#include <stdio.h>

#include <locale.h>
#include "states.h"
#include "readFromFile.h"


int main(void) {
    setlocale(LC_ALL, "RUS");
    State* arrayWithState[4];
    int dist[100][100];
    int capitals[4];
    int visited[100] = { 0 };

    int n = 0;
    int m = 0;
    int k = 0;

    const char filename[100] = "file.txt";
    readFromFile(filename, &n, &m, &k, capitals, dist);
    initializationOfStates(arrayWithState, capitals, visited, k);
    floydWarshall(n, dist);
    distributeCities(arrayWithState, n, dist, visited, k);
    printStates(arrayWithState, k);

}