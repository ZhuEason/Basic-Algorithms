/*************************************************************************
	> File Name: test.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Sun 28 Dec 2014 23:01:52 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE* fp = fopen("test.txt", "w");

	srand((unsigned)time(NULL));
	for (int i = 1; i <= 100; i++) {
			fprintf(fp, "%d ", rand()%100);
	}

	return 0;

}
