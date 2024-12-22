#include <stdio.h>
#include <stdlib.h>

#include "states.h"

typedef struct State {
    int capital;
    int cities[CITIES];
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

int findNearestCity(State* state, int n, int dist[][CITIES], int* visited) {
    int minDist = INFINITY;
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

void distributeCities(State** arrayWithStates, int n, int dist[][CITIES], int* visited, int k) {
    for (int i = 0; i < n - k; ++i) {
        for (int q = 0; q < k; ++q) {
            int nearestCity = findNearestCity(arrayWithStates[q], n, dist, visited);

            if (nearestCity != -1) {
                visited[nearestCity] = 1;
                arrayWithStates[q]->cities[arrayWithStates[q]->cityCount] = nearestCity;
                arrayWithStates[q]->cityCount++;
            }
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

void floydWarshall(int n, int dist[][CITIES]) {
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

void clean(State** arrayWithStates, int k, int dist[][CITIES]) {
    for (int i = 0; i < k; i++) {
        free(arrayWithStates[i]);
    }
    free(dist);
}

int getCapital(State** arrayWithStates, int m) {
    return arrayWithStates[m]->capital;
}

int getCityCount(State** arrayWithStates, int m) {
    return arrayWithStates[m]->cityCount;
}

int getCityByNumberInState(State** arrayWithStates, int m, int x) {
    return arrayWithStates[m]->cities[x];
}