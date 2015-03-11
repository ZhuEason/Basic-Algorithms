/*************************************************************************
	> File Name: Dijkstra.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Wed 07 Jan 2015 20:16:25 HKT
 ************************************************************************/
//the shortest path need array of distance.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7
#define MAXNUM 101

int edge[MAX][MAX];
int pre[MAX];
int distance[MAX];

void enterEdge(int, int, int);
void initial();
void display();
void dijkstra(int, int);

int main() {

	initial();

	display();

	dijkstra(1, 5);
}

void initial() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			pre[j] = -1;
			edge[i][j] = MAXNUM;
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

void enterEdge (int i, int j, int length) {
	edge[i][j] = length;
}


void display() {
	printf ("initial edge: \n");
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			printf ("%d ", edge[i][j]);
		}
		printf ("\n");
	}

	for (int i = 0; i < MAX; i++) {
		printf ("initial distance: %d ", distance[i]);
	}
	printf ("\n");
}

void dijkstra(int orig, int dest) {

	bool S[MAX];
	int nextS;
	int ceiling;

	for (int i = 0; i < MAX; i++) {
		S[MAX] = false;
	}

	//the second should be found first;
	for (int i = 1; i < MAX; i++) {
		if (edge[orig][i] < MAXNUM && !S[i]) {
			distance[i] = edge[orig][i];
		}
	}

	S[orig] = true;
	pre[orig] = -1;
	distance[orig] = MAXNUM;
	
	for (int i = 2; i < MAX; i++) {
		//find the least distance point, and add it into the S
		ceiling = MAXNUM;
		nextS = -1;	
		for (int j = 0; j < MAX; j++) {
			if (!S[j] && distance[j] < ceiling) {
				nextS = j;		
				ceiling = distance[j];
			}
		}

		if (nextS != -1) {
			printf ("nextS: %d\n", nextS);
			S[nextS] = true;
		}

		//adjust the distance
		for (int j = 1; j < MAX; j++) {
			if (!S[j] && distance[nextS] + edge[nextS][j] < distance[j]) {
				distance[j] = distance[nextS] + edge[nextS][j];
				printf ("after revising distance[%d]: %d\n", j, distance[j]);
				pre[j] = nextS;
			}
		}
	}
}
