#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "states.h"
#include "readFromFile.h"

void readFromFile(const char* filename, int dist[][CITIES], int* n) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }
    if (fscanf(file, "%d ", n) != 1) {
        return;
    }

    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *n; ++j) {
            dist[i][j] = (i == j) ? 0 : INFINITY;
        }
    }

    for (int i = 0; i < CITIES; ++i) {
        int u = 0;
        int v = 0;
        int len = 0;
        if (fscanf(file, "%d %d %d", &u, &v, &len) != 3) {
            return;
        }
        u--;
        v--;
        dist[u][v] = len;
        dist[v][u] = len;
    }
    fclose(file);
}