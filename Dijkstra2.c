/*************************************************************************
	> File Name: Dijkstra2.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Thu 08 Jan 2015 18:22:40 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7
#define MAXNUM 101

int edge[MAX][MAX];
int distance[MAX];
int pre[MAX];

void dijkstra(int );
void display();
void initial();
void enterEdge(int, int, int);
void Path(int);

int main() {
	initial();
	display();
	dijkstra(1);

	for (int i = 1; i < MAX; i++) {
		Path(i);
	}
	
	return 0;
}

void initial() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			edge[i][j] = MAXNUM;
			pre[j] = 0;
			distance[j] = MAXNUM;
		}
	}
	enterEdge(1, 2, 7);
	enterEdge(1, 3, 3);
	enterEdge(2, 3, 2);
	enterEdge(1, 2, 7);
	enterEdge(1, 6, 14);
	enterEdge(2, 4, 15);
	enterEdge(3, 6, 2);
	enterEdge(3, 4, 11);
	enterEdge(6, 5, 9);
	enterEdge(5, 4, 6);
}

void display() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			printf ("%d ", edge[i][j]);
		}
		printf ("\n");
	}
}

void enterEdge(int i, int j, int length) {
	edge[i][j] = length;
	edge[j][i] = length;
}

void dijkstra(int orig) {
	bool S[MAX];
	int ceiling;
	int shortPoint;
	
	for (int i = 0; i < MAX; i++) {
		S[i] = false;
	}

	S[orig] = true;
	pre[orig] = 0;
	distance[orig] = 0;

	for (int i = 1; i < MAX; i++) {
		if (!S[i] && edge[orig][i] < MAXNUM) {
			distance[i] = edge[orig][i];
			pre[i] = orig;
		}
	}


	for (int i = 2; i < MAX; i++) {
		//find the shortest point first
		ceiling = MAXNUM;
		for (int j = 1; j < MAX; j++) {
			if (!S[j] && distance[j] < ceiling) {
				ceiling = distance[j];
				shortPoint = j;
			}
		}
		S[shortPoint] = true;

		//adjust the shortest path;
		for (int j = 1; j < MAX; j++) {
			if (!S[j] && distance[shortPoint] + edge[shortPoint][j] < distance[j]) {
				distance[j] = distance[shortPoint] + edge[shortPoint][j];
				pre[j] = shortPoint;
			}
		}
	}
}

void Path(int dest) {
	printf ("distance[%d]:%d\n", dest, distance[dest]);
	printf ("%d", dest);

	while (pre[dest] != 0) {
		printf (" %d", pre[dest]);
		dest = pre[dest];
	}

	printf ("\n");
}
