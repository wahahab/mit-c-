#include <stdio.h>

int main(int argc, char ** argv){
	int i = 1;

print_arg:
	if (i < argc) {
		printf("%s\n", argv[i++]);
		goto print_arg;
	}
		
	return 0;
}
