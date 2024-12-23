#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "states.h"

void vertexSearch(int v, bool visited[], int dist[][CITIES], int n) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (dist[v][i] != INFINITY && !visited[i]) {
            vertexSearch(i, visited, dist, n);
        }
    }
}

void find(int dist[][CITIES], int n, bool reachEveryone[CITIES]) {
    bool visited[CITIES];

    for (int i = 0; i < n; ++i) {
        reachEveryone[i] = true;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            visited[j] = false;
        }
        vertexSearch(i, visited, dist, n);

        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                reachEveryone[j] = false;
                break;
            }
        }
    }
}

void printReachableNodes(int n, bool reachEveryone[]) {
    printf("Вершин, из которых достижимы все остальные вершины: \n");
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (reachEveryone[i]) {
            printf("%d ", i + 1);
            found = true;
        }
    }
    if (!found) {
        printf("Нет таких вершин \n");
    }
    printf("\n\n");
}