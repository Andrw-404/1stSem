#pragma once

#include <stdbool.h>

//checks if a character is an operator('+', '-', '*', '/')
bool isOperator(char ch);

// returns the priority of the given operator.
// Operators '+' and '-' have priority 1, '*' and '/' have priority 2.
// If the symbol is not an operator, 0 is returned.
int priority(char operator);

//converts a string from infix notation to a string with prefix notation
char *sortingStation(char* string);