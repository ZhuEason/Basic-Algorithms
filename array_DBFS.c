/*************************************************************************
	> File Name: DTS.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 16 Dec 2014 21:24:59 HKT
 ************************************************************************/


//BFS need the status of whether this point has been traveled, the rela
//tion among points and the queue.
//
//DFS need the status, the relation, DFS is a stack itself;
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

void createGraph(int (*)[MAX], int*);
void displayGraph(int(*)[MAX]);
void DTS(int (*)[], int*) ;
void DTScore(int (*)[], int*, int);
void BFS(int (*)[], int*);
void BFScore(int (*)[], int*, int, int*, int, int);


int main() {
	int (*graph)[MAX] = (int(*)[MAX]) malloc (sizeof(int) * MAX * MAX) ;
	int* status = (int*) malloc(sizeof (int) * MAX) ;

	createGraph(graph, status);
	displayGraph(graph);
//	DTS(graph, status);
	BFS(graph, status);
	free(graph);

	return 0;
}

void createGraph(int (*graph)[MAX], int* status) {
	int i, j;

	memset((void*)graph, 0, MAX * MAX * sizeof(int));
	memset(status, 0, MAX);
	
	printf("input start and finish: ");
	while (scanf("%d %d", &i, &j) && (! (i == 0 && j == 0))) {
		printf("input start and finish: ");
		graph[i][j] = 1;
	}
}

void displayGraph(int (*graph)[MAX]) {
	int i, j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

void DTS(int (*graph)[MAX], int *status) {
	int i; 
	printf("DFS start~\n");

	for (i = 0; i < MAX; i++) {
		DTScore(graph, status, i);
	}
}
void DTScore(int (*graph)[MAX], int *status, int i) {
	int j;

	for (j = 0; j < MAX; j++) {
		if (graph[i][j] == 1 && status[j] == 0) {
			status[j] = 1;
			printf("%d--->%d", i, j);
			DTScore(graph, status, j);
		}
	}
}

void BFS(int (*graph)[MAX], int *status) {

	printf("BFS start~\n");

	int i = 0; 

	int queue[MAX];
	int rear = 0;
	int tail = 0;

	for (i = 0; i < MAX; i++) {
		BFScore(graph, status, i, queue, rear, tail);
	}
}
void BFScore(int (*graph)[MAX], int *status, int i, int* queue, int rear, int tail) {
	int j;

	if (rear <= tail) {
		for (j = 0; j < MAX; j++) {
			if (graph[i][j] == 1 && status[j] == 0) {
				status[j] = 1;
				printf("%d--->%d", i, j);
				tail = tail + 1;
				queue[tail] = j;
			}
		}
		BFScore(graph, status, queue[rear+1], queue, rear+1, tail);
	}
}


