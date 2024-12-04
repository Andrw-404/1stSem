#pragma once

typedef struct htItem htItem;

typedef struct hashTable hashTable;

//function that creates a hash table
hashTable* createTable(int size);

//function that deletes a hash table element
void deleteItem(htItem* item);

//function that deletes the hash table
void deleteTable(hashTable* table);

//hash function
int hash(char* key, int size);

//function for inserting an item into a hash table
void insert(hashTable* table, char* key);