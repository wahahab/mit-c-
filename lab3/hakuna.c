#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = (char *) malloc(sizeof(char) * 256);

    strcpy(str, "hakuna matata!");
    // this line should copy "hakuna matata!"
    // into our char array
    printf("%s\n", str);
    // Anything else?
    free(str);
    return 0;
}

