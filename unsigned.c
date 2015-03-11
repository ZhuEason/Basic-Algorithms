#include <stdio.h>

int main() {
	int d = -1;
	const char* p = "I love you\n";

	if (d < (unsigned int)1) {
		printf("%d\n", d);
		printf("the signed number was not converted\n");
	} else {
		printf("%u\n", d);
		printf("the signed number was converted\n");
	}

	return 0;
}

