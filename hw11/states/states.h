#pragma once

#define INFINITY 10000000
#define CITIES 100

typedef struct State State;

// function to initialize an array of states
void initializationOfStates(State** arrayWithStates, int* capitals, int* visited, int k);

// function to find the nearest city for the state
int findNearestCity(State* state, int n, int dist[][CITIES], int* visited);

// function for distributing the remaining cities between states
void distributeCities(State** arrayWithStates, int n, int dist[][CITIES], int* visited, int k);

// function to display information about all states and their cities
void printStates(State** states, int k);

// Floyd-Warshell algorithm
void floydWarshall(int n, int dist[][CITIES]);

// function to clear allocated memory for the matrix and for all state structures
void clean(State** arrayWithStates, int k, int dist[][CITIES]);

// function to get the capital of a state by index
int getCapital(State** arrayWithStates, int m);

// function to get the number of cities in the state
int getCityCount(State** arrayWithStates, int m);

// function to get a city by its number in the state
int getCityByNumberInState(State** arrayWithStates, int m, int x);