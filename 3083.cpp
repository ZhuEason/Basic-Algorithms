/*************************************************************************
	> File Name: 3083.cpp
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Thu 25 Dec 2014 12:59:36 HKT
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>

#define MAX 41

using namespace std;

//record the location of the traveler.
typedef struct node {
	int x;
	int y;
	struct node* pre; // point to the pre location
}location;

void BFS (char(*)[MAX], queue<location*> &q, location* lastLocation );
void DFS_LF (char(*)[MAX], stack<location*> &q, location* lastLocation, int&);
bool findPath(char(*)[MAX], location* &q, int& );
void display(location*);

int main() {
	
	char maze[MAX][MAX];
	int test;
	int row, coloum;

	scanf("%d", &test);

	while (test--) {
		
		location *firstLocation = NULL;
		location *lastLocation = NULL;
		queue<location*> q;		
		stack<location*> s;

		memset(maze, '#', sizeof(char) * 41 * 41);
		int i, j;
		int direction;

		scanf("%d %d", &coloum, &row);	
		for (i = 1; i <= row; i++) {
			for (j = 1; j <= coloum; j++) {
				scanf(" %c", &maze[i][j]);
				if (maze[i][j] == 'S') {
					firstLocation = (location*) malloc (sizeof(location));
					firstLocation->x = j;
					firstLocation->y = i;
					firstLocation->pre = NULL;
				} else if (maze[i][j] == 'E') {
					lastLocation = (location*) malloc (sizeof(location));
					lastLocation->x = j;
					lastLocation->y = i;
					firstLocation->pre = NULL;
				}
			}
		}
		
		q.push(firstLocation);
		s.push(firstLocation);

		if (firstLocation->x == 1) {
			direction = 1;
		} else if (firstLocation->x == coloum) {
			direction = 3;
		} else if (firstLocation->y == 1) {
			direction = 2;
		} else if (firstLocation->y == row) {
			direction = 0;
		}
		DFS_LF (maze, s, lastLocation, direction);

		//BFS(maze, q, lastLocation);


	}

	return 0;
}

void BFS(char (*maze)[MAX] , queue<location*> &q, location* lastLocation ) {

	 int i;
	 location* currentLocation = NULL;

	 if (!q.empty()) {
		currentLocation = q.front();
		for (i = 0; i < 4; i++) {
			if (findPath(maze, currentLocation, i) == false) {
				continue;
			} else {
				q.push(currentLocation);
			}
		}
		if (currentLocation->x == lastLocation->x && currentLocation->y == lastLocation->y) {
			while ( !q.empty() ) {
				q.pop();
			}
			return ;
		}
		q.pop();
		BFS(maze, q, lastLocation);
	 }
}

void DFS_LF (char(*maze)[MAX], stack<location*> &s, location* lastLocation, int& direction) {
	int i;

	location* currentLocation = NULL;
	
	if (!s.empty()) {
		currentLocation = s.top();	
		for (i = 0; i < 4; i++) {
			if (findPath(maze, currentLocation, direction)) {
				s.push(currentLocation);
				if (currentLocation->x == lastLocation->x && currentLocation->y == lastLocation->y) {
					display(currentLocation);
					while (!s.empty()) {
						s.pop();
					}
				}
				DFS_LF(maze, s, lastLocation, direction);
			}
		}
		s.pop();
	}
}


bool findPath(char(*maze)[MAX] , location* &firstLocation, int& direction) {
	
	int tempX = firstLocation->x;
	int tempY = firstLocation->y;

	switch( (direction+3) % 4 ) {
		case 0:
			tempY--; 
			direction = 0;
			break;
		case 1:
			tempX++;
			direction = 1;
			break;
		case 2:
			tempY++;
			direction = 2;
			break;
		case 3:
			tempX--;
			direction = 3;
			break;
		default:
			break;
	} 

	if (maze[tempY][tempX] == '.'){
		location* currentLocation = (location*) malloc (sizeof (location));
		currentLocation->x = tempX;
		currentLocation->y = tempY;
		currentLocation->pre = firstLocation;
		
		firstLocation = currentLocation;
		maze[tempY][tempX] = '#';

		return true;
	} 
	if (maze[tempY][tempX] == 'E') {
		location* currentLocation = (location*) malloc (sizeof (location));
		currentLocation->x = tempX;
		currentLocation->y = tempY;
		currentLocation->pre = firstLocation;

		firstLocation = currentLocation;

		display (currentLocation);

		return true;
	}

	return false;
}

void display (location* lastLocation) {
	 printf("(%d, %d)", lastLocation->y, lastLocation->x);
	 lastLocation = lastLocation->pre;
	 
	 while (lastLocation != NULL) {
		 printf("---->(%d, %d)", lastLocation->y, lastLocation->x);
		 lastLocation = lastLocation->pre;			
	 }

	 printf("\n");
}
