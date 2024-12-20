#pragma once

typedef struct State State;

void initializationOfStates(State** arrayWithStates, int* capitals, int* visited, int k);

int findNearestCity(State* state, int n, int dist[][100], int* visited);

void distributeCities(State** states, int n, int dist[][100], int* visited, int k);

void printStates(State** states, int k);

void floydWarshall(int n, int dist[][100]);


