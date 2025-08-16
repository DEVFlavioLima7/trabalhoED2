#include <string.h>
#include <ctype.h>
#include "../funcoes/BB_utils.h"

// Compara strings ignorando maiúsculas/minúsculas
int compararStrings(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        char c1 = tolower((unsigned char)*str1);
        char c2 = tolower((unsigned char)*str2);

        if (c1 != c2) {
            return c1 - c2;
        }

        str1++;
        str2++;
    }
    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}