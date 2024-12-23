#pragma once

#define INFINITY 10000000
#define CITIES 100

#include <stdbool.h>

// deep crawl
void vertexSearch(int v, bool visited[], int dist[][CITIES], int n);

// search for vertices from which all are reachable
void find(int dist[][CITIES], int n, bool reachEveryone[CITIES]);

// output of vertices from which all other vertices are reachable
void printReachableNodes(int n, bool reachEveryone[]);
