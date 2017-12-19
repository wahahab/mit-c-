#include <stdio.h>

int main (void) {
	int val = 0;
	int next;

	for (next = 1; next <= 100; next++) {
		val += next;
		printf("%d ", val);
	}
	printf("\n");
	return 0;
}
