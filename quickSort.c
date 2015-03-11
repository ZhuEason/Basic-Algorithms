/*************************************************************************
	> File Name: quickSort.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Mon 26 Jan 2015 23:37:09 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void quickSort (int [], int, int);
void quick(int [], int, int);

int main() {
	FILE* fp = fopen("test.txt", "rt");
	int num[MAX];

	for (int i = 0; i < MAX; i++) {
		fscanf(fp, "%d", &num[i]);
	}

//	quickSort(num, 0, MAX-1);
	quick(num, 0, MAX-1);

	return 0;
}


void quickSort (int num[], int l, int h) {
	int i, j;
	int key;
	
	for (i = 0; i < MAX; i++) {
		printf ("%d ", num[i]);
	}
	printf ("\n");

	if (l < h) {
		i = l;
		j = h;
		key = num[i];

		while (i < j) {

			while (i < j && num[j] >= key) {
				j--;
			}
			num[i] = num[j];

			while (i < j && num[i] < key) {
				i++;
			}
			num[j] = num[i];

		}
		num[j] = key;

		quickSort (num, l, j);
		quickSort (num, j+1, h);
	}
}

void quick(int num[], int l, int h) {
	if (h > l) {
		int key = num[l];
		int i = l;
		int j = h;

		while (i < j) {
			while (i < j && num[j] >= key) {
				j--;
			}
			num[i] = num[j];

			while (i < j && num[i] < key) {
				i++;
			}
			num[j] = num[i];
		}
		num[j] = key;

		quick(num, l, j);
		quick(num, j+1, h);
	}
}
