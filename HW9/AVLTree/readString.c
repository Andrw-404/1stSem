#include <stdio.h>
#include <string.h>

#include "readString.h"

void readString(char* buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}