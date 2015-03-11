/*************************************************************************
	> File Name: Bellman.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Wed 14 Jan 2015 09:20:56 HKT
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 7
#define MAXNUM 101

int graph[MAX][MAX];
int pre[MAX];
int distance[MAX];

int bellman(int ,int);
void initialization(int);
void enterEdge(int, int, int);

int main() {
	int orig, dest;

	while (scanf ("%d %d", &orig, &dest) != EOF) {
		initialization(orig);
		printf ("%d\n", bellman(orig, dest));
		
		while (dest != orig) {
			printf ("%d ", pre[dest]);
			dest = pre[dest];
		}
		printf ("\n");
	}

	return 0;
}

void initialization(int orig) {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} else {
				graph[i][j] = MAXNUM;
			}
		}
	}

	enterEdge(1, 2, 7);
	enterEdge(1, 3, 3);
	enterEdge(3, 2, -2);
	enterEdge(3, 5, 14);
	enterEdge(2, 4, 15);
	enterEdge(2, 5, 7);
	enterEdge(5, 4, -2);
	enterEdge(4, 6, 4);
	enterEdge(5, 6, 5);

	for (int i = 1; i < MAX; i++) {
		distance[i] = graph[orig][i];
		if (graph[orig][i] < MAXNUM) {
			pre[i] = orig;
		}
	}

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			printf ("%d ", graph[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");
}

void enterEdge(int orig, int dest, int length) {
	graph[orig][dest] = length;
}

int bellman(int orig, int dest) {

	// MAX-1 rounds, for the maximum steps between orig to dest are max-1
	for (int i = 2; i < MAX; i++) {
		for (int t = 1; t < MAX; t++) {
			printf ("%d ", distance[t]);
		}
		printf ("\n");

		//All the distance[j] except orig should be adjusted
		for (int j = 1; j < MAX; j++) {
			if (j == orig) {
				continue;
			}
			//all other points except j-point should be considered whether it can reach the j shorter
			for (int k = 1; k < MAX; k++) {
				if (j == k) {
					continue;
				}

				if (distance[k] != MAXNUM && graph[k][j] + distance[k] < distance[j]) {
					distance[j] = graph[k][j] + distance[k];
					pre[j] = k;
				} 
			}
		}
	}

	return distance[dest];
}
