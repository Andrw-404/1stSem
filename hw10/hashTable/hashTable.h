#pragma once

#include <stdbool.h>

typedef struct HashTable HashTable;

//function that creates a hash table
HashTable* createTable(int size);

//hash function
int hash(char* key, int size);

//function for inserting an item into a hash table
void insert(HashTable* table, char* key);

//function to get hash table fill factor
double getFillFactor(HashTable* table);

//function for obtaining the number of non - empty lists
int getNumberOfNonEmptyLists(HashTable* table);

//function for obtaining the average list length
float averageLength(HashTable* table);

//function for obtaining the value of the maximum list length
int findingTheMaximumLength(HashTable* table);

//function to read a file and output words with their frequency
void readAndPrint(const char* filename, HashTable* table);

//function for deleting a hash table
void removeTable(HashTable* table);

//function for finding the key among the buckets
bool searchInBuckets(HashTable* table, const char* key);

//function for deleting characters after a word
void cleanWord(char* word);