#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct HashTable HashTable;

//function that creates a hash table
HashTable* createTable(size_t size, int* errorCode);

//hash function
int hash(char* key, size_t size);

//function for inserting an item into a hash table
void insert(HashTable* table, char* key, int* errorCode);

//function for deleting a hash table
void removeTable(HashTable* table, int* errorCode);

//function for finding the key among the buckets
bool searchInBuckets(HashTable* table, char* key, int* errorCode);
