#include "to_uppercase.h"
#include <ctype.h>  // for toupper()

void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

