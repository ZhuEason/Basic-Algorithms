/*************************************************************************
	> File Name: maze_RF.cpp
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Sun 28 Dec 2014 14:48:24 HKT
 ************************************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

#define MAX 41

using namespace std;

typedef struct node {
	int x;
	int y;
	struct node* pre;
} location;

void DFS_RF (location*, int);
void DFS_LF (location*, int);
void BFS (queue<location*> &);
int findDirection (location*, location*);
int createGraph(location*&, int, int);
bool findPath(location*, location* &, int, int);
void copy();
void display(location*);
void deleteQueue(queue<location*> &);

int test;
char oGraph[MAX][MAX];
char graph[MAX][MAX];
bool success;
int count;

int main() {

	int row, coloum;
	int direction;
	location* firstLocation;
	queue<location*> q;

	scanf("%d", &test);
	
	while (test--) {
		scanf("%d %d", &coloum, &row);
		direction = createGraph(firstLocation, row, coloum);

		count = 0;
		success = false;
		copy();
		DFS_LF (firstLocation, direction);

		count = 0;
		success = false;
		copy();
		DFS_RF (firstLocation, direction);

		count = 0;
		success = false;
		copy();
		q.push(firstLocation);
		BFS (q);
		deleteQueue(q);
	}

	return 0;
}

void BFS (queue<location*> &q) {
	
	location* currentLocation = q.front();
	location* nextLocation = NULL;
	
	if (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			if (findPath (currentLocation, nextLocation, i, 0)) {
				if (success) {
					display(nextLocation);
					return;
				}
				q.push(nextLocation);
			}
		}
	
		q.pop();
		BFS (q);
	}
}

void DFS_LF (location* currentLocation, int direction) {

	count++;
	location* nextLocation = NULL;

	//printf("currentLocaion:(%d, %d) count:%d", currentLocation->x, currentLocation->y, count);

	for (int i = 0; i < 6; i++) {
		if (findPath(currentLocation, nextLocation, direction, 3)) {
			direction = findDirection (nextLocation, currentLocation);
	//		printf("direction: %d\n", direction);
			DFS_LF (nextLocation, direction);
			if (success) {
				return;
			}
			direction = (direction+1) % 4;
		}
		direction++;
	}

	if (success) {
		printf("%d ", count);
		return;
	}

	count++;
}

void DFS_RF (location* currentLocation, int direction) {

	count++;
	location* nextLocation = NULL;

//	printf("currentLocaion:(%d, %d) count:%d", currentLocation->x, currentLocation->y, count);

	for (int i = 0; i < 6; i++) {
		if (findPath(currentLocation, nextLocation, direction, 1)) {
			direction = findDirection (nextLocation, currentLocation);
//			printf("direction: %d\n", direction);
			DFS_RF (nextLocation, direction);
			if (success) {
				return;
			}
			direction = (direction+1) % 4;
		}
		direction++;
	}

	if (success) {
		printf("%d ", count);
		return;
	}

	count++;
}

int findDirection (location* nextLocation, location* currentLocation) {

	int direction;

	if (nextLocation->x - currentLocation->x == 1) {
		direction = 1;
	} else if (nextLocation->x - currentLocation->x == -1) {
		direction = 3;
	} else if (nextLocation->y - currentLocation->y == 1) {
		direction = 2;
	} else if (nextLocation->y - currentLocation->y == -1) {
		direction = 0;
	}

	return direction;
}

bool findPath(location* currentLocation, location* &nextLocation, int direction, int flag) {
	int choice = (direction + flag) % 4;
	int tempX = currentLocation->x;
	int tempY = currentLocation->y;

	switch (choice) {
		case 0:
			tempY--;
			break;
		case 1:
			tempX++;
			break;
		case 2:
			tempY++;
			break;
		case 3:
			tempX--;
			break;
	}

	if (graph[tempY][tempX] == '.') {
		nextLocation = (location*) malloc (sizeof (location));
		nextLocation->x = tempX;
		nextLocation->y = tempY;
		nextLocation->pre = currentLocation;

		graph[tempY][tempX] = '#';

		return true;
	} else if (graph[tempY][tempX] == 'E') {
		nextLocation = (location*) malloc(sizeof (location));
		nextLocation->x = tempX;
		nextLocation->y = tempY;
		nextLocation->pre = currentLocation;

		graph[tempY][tempX] = '#';

		success = 1;

		return true;
	}

	return false;
}

void copy() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			graph[i][j] = oGraph[i][j];
		}
	}
}

int createGraph(location* &firstNode, int row, int coloum) {
	int direction;

	memset(oGraph, '#', sizeof (char) * MAX * MAX);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= coloum; j++) {
			scanf(" %c", &oGraph[i][j]);
			if (oGraph[i][j] == 'S') {

				firstNode = (location*) malloc (sizeof (location));
				firstNode->x = j;
				firstNode->y = i;
				firstNode->pre = NULL;

				if (i == 1) {
					direction = 2;
				} else if (i == row) {
					direction = 0;
				} else if (j == 1) {
					direction = 1;
				} else if (j == coloum) {
					direction = 3;
				}
			}
		}
	}

	return direction;
}

void display (location* lastLocation) {

	while (lastLocation != NULL) {
		count++;
		lastLocation = lastLocation->pre;
	}

	printf("%d\n", count);
}

void deleteQueue (queue<location*>& q) {
	while (!q.empty()) {
		q.pop();
	}
}
