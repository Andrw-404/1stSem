#include "testForTask.h"
#include "reckoning.h"

#include <stdbool.h>

bool reckoningTest() {
    int testResult = reckoning(8, 3);
    if (testResult != 7) {
        return false;
    }
    return true;
}