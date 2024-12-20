#define INF 10000000

#include <stdio.h>
#include <stdlib.h>

typedef struct State {
    int capital;
    int cities[10];
    int cityCount;
} State;

void initializationOfStates(State** arrayWithStates, int* capitals, int* visited, int k) {
    for (int i = 0; i < k;  i++) {
        visited[capitals[i]] = 1;
        arrayWithStates[i] = (State*)malloc(sizeof(State));
        arrayWithStates[i]->capital = capitals[i];
        arrayWithStates[i]->cities[0] = capitals[i];
        arrayWithStates[i]->cityCount = 1;
    }
}

int findNearestCity(State* state, int n, int dist[][100], int* visited) {
    int minDist = INF;
    int nearestCity = -1;

    for (int i = 0; i < state->cityCount; ++i) {
        int city = state->cities[i];
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[city][j] < minDist) {
                minDist = dist[city][j];
                nearestCity = j;
            }
        }
    }
    return nearestCity;
}

void distributeCities(State** arrayWithStates, int n, int dist[][100], int* visited, int k) {
    for (int i = 0; i < n - k; ++i) {
        int nearestState = -1;
        int nearestCity = -1;
        int minDist = INF;
        for (int q = 0; q < k; ++q) {
            int city = findNearestCity(arrayWithStates[q], n, dist, visited);
            if (city != -1 && dist[arrayWithStates[q]->cities[arrayWithStates[q]->cityCount - 1]][city] < minDist) {
                minDist = dist[arrayWithStates[q]->cities[arrayWithStates[q]->cityCount - 1]][city];
                nearestState = q;
                nearestCity = city;
            }
        }
        if (nearestCity != -1) {
            visited[nearestCity] = 1;
            arrayWithStates[nearestState]->cities[arrayWithStates[nearestState]->cityCount] = nearestCity;
            arrayWithStates[nearestState]->cityCount++;
        }
    }
}


void printStates(State** arrayWithStates, int k) {
    for (int i = 0; i < k; ++i) {
        printf("Государство %d со столицей %d: ", i + 1, arrayWithStates[i]->capital + 1);
        for (int q = 0; q < arrayWithStates[i]->cityCount; q++) {
            printf("%d ", arrayWithStates[i]->cities[q] + 1);
        }
        printf("\n");
    }
}

void floydWarshall(int n, int dist[][36]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}