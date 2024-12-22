#pragma once

// function for reading all the necessary information from a file and filling in the adjacency matrix.
// (n - number of cities; m - number of roads; u - first city of the road, v - second city of the road, 
// len - length of the road between these two cities; k - number of capitals)
void readFromFile(const char* filename, int* n, int* m, int* k, int* capitals, int dist[][CITIES]);
