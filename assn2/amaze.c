#include <stdio.h>
#define N 10

void amaze1() {
	int i;

	for (i = 0 ; i <= N ; i++)
		if (i % 2 == 1) printf("%d ", i);
	printf("\n");
}
void amaze2() {
	int i;
	
	for (i = 1; i <= N; i += 2)
		printf("%d ", i);
	printf("\n");
}
void amaze3() {
	int i;
	int n = N % 2 == 0 ? N : N + 1;

	for (i = 1; i <= n / 2; i += 2) {
		printf("%d ", i);
		if (i != n - i)
			printf("%d ", n - i);
	}
	printf("\n");
}
void amaze4() {
	printf("1 ");
	printf("3 ");
	printf("5 ");
	printf("7 ");
	printf("9");
	printf("\n");
}
void amaze5() {
	int i = 1;
	
	do {
		printf("%d ", i);
		i += 2;
	} while (i <= N);
	printf("\n");
}
void amaze6() {
	int i = 0;
	
	do {
		if (i % 2 == 1)
			printf("%d ", i);
	} while (++i <= N);
	printf("\n");
}
void amaze7() {
	int i = 0;

	goto check;
check:
	if (i > N)
		goto done;
	if (i % 2 == 1) {
		printf("%d ", i);
	}
	goto add;
add:
	i++;
	goto check;
done:
	printf("\n");
}
int main(void) {
	amaze1();
	amaze2();
	amaze3();
	amaze4();
	amaze5();
	amaze6();
	amaze7();

	return 0;
}
