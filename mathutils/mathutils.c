#include "mathutils.h"

int division(int x, int y) {
    if (y == 0) {
        return 0; // simple error handling (avoid divide by zero)
    }
    return x / y;
}

int multiple(int x, int y) {
    return x * y;
}
