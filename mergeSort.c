/*************************************************************************
	> File Name: mergeSort.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Tue 27 Jan 2015 15:58:27 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void mergeSort(int [], int, int, int[]);
void mergeSplit(int [], int, int, int[]);

int main() {
	FILE* fp = fopen("test.txt", "r");
	int num[MAX];
	int temp[MAX];

	printf ("the original array:\n");
	for (int i = 0; i < MAX; i++) {
		fscanf(fp, "%d ", &num[i]);
		printf ("%d ", num[i]);
	}
	printf ("\n");

	mergeSplit(num, 0, MAX-1, temp);
}

void mergeSplit(int num[], int l, int h, int temp[]) {
	if (l < h) {
		mergeSplit(num, l, (l+h)/2, temp);
		mergeSplit(num, (l+h)/2+1, h, temp);
		mergeSort(num, l, h, temp);
	}
}

void mergeSort(int num[], int l, int h, int temp[]) {
	int mid = (l + h)/2;
	int i = l, j = mid + 1;
	int k = 0;

	while (i <= mid && j <= h) {
		if (num[i] <= num[j]) {
			temp[k] = num[i];
			i++;
			k++;
		} else {
			temp[k] = num[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		temp[k] = num[i];
		i++;
		k++;
	}
	while ( j <= h) {
		temp[k] = num[j];
		j++;
		k++;
	}

	k = 0;
	for (i = l; i <= h; i++) {
		num[i] = temp[k++];
	}

	printf ("l: %d, h: %d\n", l, h);
	for (int p = l; p <= h; p++) {
		printf ("%d ", num[p]);
	}
	printf ("\n");

}
