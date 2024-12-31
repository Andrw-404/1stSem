#pragma once

#include <stdbool.h>

//tests the creation of a new empty list
bool testCreateList();

//tests a function that returns the value of an element by its position in the list
bool testGetValue();

//tests a function that changes the value of an element by position
bool testSetValue();

//tests a function that checks whether an element is the last element in the list
bool testIsLast();

//tests a function that checks if the list is empty
bool testIsEmpty();

//tests the function of adding an element to the end of the list
bool testAddLast();

//function for running tests
bool runTests();