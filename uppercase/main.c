#include <stdio.h>
#include <string.h>
#include "to_uppercase.h"

#define MAXLEN 100

int main() {
    char input[MAXLEN];

    printf("Enter a string: ");
    if (fgets(input, MAXLEN, stdin) != NULL) {
        // Remove trailing newline from fgets
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        to_uppercase(input);
        printf("Uppercase: %s\n", input);
    }

    return 0;
}
