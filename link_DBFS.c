/*************************************************************************
	> File Name: link_DFS.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Tue 23 Dec 2014 17:00:15 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

typedef struct point {
	int vertex;
	struct point* next;
} point;

void createEdge(point**, int, int);
void deleteGraph(point**);
void printGraph(point**);
void DFS(point**, int*);
void DFScore(point**, int, int*);
void BFS(point**, int*);
void BFScore(point**, int, int*, int*, int, int);

int main() {
	int status[MAX];
	point** graph = NULL;
	graph = (point**) malloc (sizeof (point*) * MAX);

	memset(graph, 0, sizeof (point*) * MAX);
	memset(status, 0, sizeof (int) * MAX);

	createEdge(graph, 0, 1);
	createEdge(graph, 0, 2);
	createEdge(graph, 0, 3);
	createEdge(graph, 1, 6);
	createEdge(graph, 2, 4);
	createEdge(graph, 2, 5);

	printGraph(graph);

//  DFS(graph, status);
	BFS(graph, status);

	return 0;
}

void createEdge(point** graph, int head, int tail) {
	point* tailNode = (point*) malloc (sizeof (point));	
	tailNode->vertex = tail;
	tailNode->next = NULL;

	point** headNode = (graph + head);

	while (*headNode != NULL) {
		headNode = &((*headNode)->next);	
	}
	
	*headNode = tailNode;
}


void printGraph(point** graph) {
	int start;

	for (start = 0; start < MAX; start++) {
		point* currentNode = *(graph + start);
		printf("%d", start);

		while (currentNode != NULL) {
			printf("----->%d", currentNode->vertex);
			currentNode = currentNode->next;
		}
		printf("\n");
	}
}

void deleteGraph(point** graph) {
	int start;

	for (start = 0; start < MAX; start++) {
		point* currentNode = *(graph + start);
		point* tempNode = NULL;

		while (currentNode != NULL) {
			tempNode = currentNode;
			currentNode = currentNode->next;
			free(tempNode);
		}

		*(graph + start) = NULL;
	}
}

void DFS (point** graph, int* status) {
	int start;
	
	printf("DFS start!\n");
	for (start = 0; start < MAX; start++) {
		printf("%d", start);
		DFScore(graph, start, status);
	}
}

void DFScore(point** graph, int start, int* status) {
	
	point* currentPoint = *(graph + start);

	while ( currentPoint != NULL ) {
		if (status[currentPoint->vertex] == 0) {
			printf("---->%d", currentPoint->vertex);
			status[currentPoint->vertex] = 1;
			DFScore(graph, currentPoint->vertex, status);
		}
		printf("\n");
		currentPoint = currentPoint->next;
	}
}

void BFS (point** graph, int* status) {
	int j;
	int queue[MAX];
	int head = 0;
	int tail = 0;

	memset(queue, 0 , sizeof(int)*MAX);
	printf("BFS start!\n");

	for ( j = 0; j < MAX; j++) {
		printf("%d", j);
		status[j] = 1;
		BFScore(graph, j, status, queue, head, tail );
	}
}
void BFScore (point** graph, int start, int* status, int* queue, int rear, int tail) {
	point* currentPoint = *(graph + start);
	if (rear <= tail) {

		while (currentPoint != NULL) {
			if (status[currentPoint->vertex] == 0) {
				printf("---->%d", currentPoint->vertex);
				status[currentPoint->vertex] = 1;
				tail += 1;
				queue[tail] = currentPoint->vertex;
			}
			currentPoint = currentPoint->next;
		}
	
		BFScore( graph, queue[rear+1], status, queue, rear+1, tail);
		printf("\n");
	}
}


