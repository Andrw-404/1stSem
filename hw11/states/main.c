#include <stdio.h>

#include "states.h"
#include "readFromFile.h"


int main(void) {
    int dist[100][100];
    int capitals[100];
    int visited[100];

    int n = 0;
    int m = 0;
    int k = 0;

    const char filename[100] = "file.txt";
    readFromFile(filename, &n, &m, &k, capitals, dist);
}