#pragma once

#include <stdbool.h>

//function in which mathematical operations take place
int postfixCalculator(char* string);

//function that checks that the divisor is not zero
bool divisorCheck(int divisor, char* token);

//the function checks for invalid operators (such as ‘(’ , ‘. “, ”[’, ‘}’, etc.).
bool operatorChecking(char* token);