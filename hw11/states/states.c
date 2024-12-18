#define INF 10000000

#include <stdio.h>

int visited[100];

typedef struct State {
    int capital;
    int cities[100];
    int cityCount;
} State;

State arrayWithState[100];

void initializationOfStates(State* states, int* capitals, int k) {
    for (int i = 0; i < k;  i++) {
        visited[capitals[i]] = 1;
        states[i].capital = capitals[i];
        states[i].cities[0] = capitals[i];
        states[i].cityCount = 1;
    }
}

int findNearestCity(State* state, int n, int dist[100][100], int* visited) {
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

void distributeCities(State* states, int n, int dist[100][100], int k) {
    for (int i = 0; i < n - k; ++i) {
        int nearestState = -1;
        int nearestCity = -1;
        int minDist = INF;
        for (int q = 0; q < k; ++q) {
            int city = findNearestCity(&states[q], n, dist, visited);
            if (city != -1 && dist[states[q].cities[states[q].cityCount - 1]][city] < minDist) {
                minDist = dist[states[q].cities[states[q].cityCount - 1]][city];
                nearestState = q;
                nearestCity = city;
            }
        }
        if (nearestCity != -1) {
            visited[nearestCity] = 1;
            states[nearestState].cities[states[nearestState].cityCount] = nearestCity;
            states[nearestState].cityCount++;
        }
    }
}

void printStates(State* states, int k) {
    for (int i = 0; i < k; ++i) {
        printf("Государство %d со столицей %d: ", i + 1, states[i].capital + 1);
        for (int q = 0; q < states[i].cityCount; q++) {
            printf("%d ", states[i].cities[q] + 1);
        }
        printf("\n");
    }
}

void floydWarshall(int n, int dist[100][100]) {
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