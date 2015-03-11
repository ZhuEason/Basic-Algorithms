/*************************************************************************
	> File Name: 3083.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Thu 25 Dec 2014 10:20:49 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>

#define MAX 41
//record the location of the traveler.
typedef struct node {
	int x;
	int y;
	struct node* pre; // point to the pre location
}presentLocation;

int main() {
	
	char maze[MAX][MAX];
	int test;
	int row, coloum;

	scanf("%d", &test);

	while (test--) {
		
		memset(maze, 0, sizeof(char) * 41 * 41);
		int i, j;
		scanf("%d %d", &coloum, &row);	
		for (i = 1; i <= coloum; i++) {
			for (j = 1; j <= row; j++) {
				scanf(" %c", &maze[coloum][row]);
			}
		}

		BFS(ma)
	}
}

void BFS(char(*)[MAX] maze, location* currentLocation ) {
		
}

void findPath(char(*)[] maze, int i, int j) {
	
}
