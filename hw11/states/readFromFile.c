#include <stdio.h>

#define INF 10000000

void readFromFile(const char* filename, int* n, int* m, int* k, int* capitals, int (*dist)[6]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    fscanf(file, "%d %d", n, m);

    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *n; ++j) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < *m; ++i) {
        int u = 0;
        int v = 0;
        int len = 0;
        fscanf(file, "%d %d %d", &u, &v, &len);
        u--;
        v--;
        dist[u][v] = len;
        dist[v][u] = len;
    }
    
    fscanf(file, "%d", k);
    for (int i = 0; i < *k; ++i) {
        fscanf(file, "%d", &capitals[i]);
        capitals[i]--;
    }
    fclose(file);
}