#include <stdio.h>

union val {
    unsigned int i;
    char b[4];
};

int main(void) {
    union val v;
    int i;

    v.i = 0x01010101;
    for (i = 3; i > -1; i--)
        printf("%d ", v.b[i]);
    printf("\n");

    return 0;
}
