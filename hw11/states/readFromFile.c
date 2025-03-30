#include <stdio.h>

#include "states.h"

void readFromFile(const char* filename, int* n, int* m, int* k, int* capitals, int dist[][CITIES]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    if (fscanf(file, "%d %d", n, m) != 2) {
        return;
    }

    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *n; ++j) {
            dist[i][j] = (i == j) ? 0 : INFINITY;
        }
    }

    for (int i = 0; i < *m; ++i) {
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
    
    if (fscanf(file, "%d", k) != 1) {
        return -1;
    }

    for (int i = 0; i < *k; ++i) {
        if (fscanf(file, "%d", &capitals[i]) != 1) {
            return -1;
        }
        capitals[i]--;
    }
    fclose(file);
}