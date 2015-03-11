/*************************************************************************
	> File Name: 1860.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Mon 26 Jan 2015 09:14:44 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float rate[101][101];
float commission[101][101];
float distance[101];

void bellman(int, int, int, float);
void enterEdge(int, int, float, float, float, float);
void initial(int);
float exchange(int, int, float);
void display(int);

int main() {
	int N, M, S;
	float V;
	int A, B; 
	float Rab, Cab, Rba, Cba; 


	scanf("%d %d %d %f", &N, &M, &S, &V);
	initial(N);
	for (int i = 0; i < M; i++) {
		scanf ("%d %d %f %f %f %f", &A, &B, &Rab, &Cab, &Rba, &Cba);
		enterEdge(A, B, Rab, Cab, Rba, Cba);
	}
	display(N);

	bellman(N, M, S, V);
}

void enterEdge(int A, int B, float Rab, float Cab, float Rba, float Cba) {
	rate[A][B] = Rab;
	rate[B][A] = Rba;

	commission[A][B] = Cab;
	commission[B][A] = Cba;
}

void initial(int N) {
	memset(rate, 22, sizeof(rate[0][0])*101*101);
	memset(commission, 10000, sizeof(commission[0][0])*101*101);
	memset(distance, 0, sizeof(distance[0])*101);


	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			commission[i][j] = 10000;
		}
	}

	for (int i = 1; i <= 2*N; i++) {
		commission[i][i] = 0;
	}
}

void display(int N) {

	printf ("rate:\n");
	for (int i = 1; i <= 2*N; i++){
		for (int j = 1; j <= 2*N; j++) {
			printf ("%f ", rate[i][j] );
		}
		printf ("\n");
	}

	printf ("commmission:\n");
	for (int i = 1; i <= 2*N; i++){
		for (int j = 1; j <= 2*N; j++) {
			printf ("%f ", commission[i][j]);
		}
		printf ("\n");
	}
}

float exchange(int A, int B, float orig) {

	float exchange = (orig-commission[A][B]) * rate[A][B] > orig ? (orig-commission[A][B]) * rate[A][B] : orig;

	return exchange;
}

void bellman(int N, int M, int S, float V) {
	//find the distance[i]
	for (int i = 1; i <= N; i++) {
		int money = (V-commission[S][i]) * rate[S][i];
		if (money > 0) {
			distance[i] = money;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		printf ("distance[%d]: %f ",i , distance[i]);
	}
	printf ("\n");

	for (int i = 1; i <= 2*M; i++) {
		printf ("\nround %d:\n", i);
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (k == j) {
					continue;
				}
				distance[j] = exchange(k, j, distance[j]);
				printf ("distance[%d]: %f ", j, distance[j]);
			}
			printf ("\n");
		}
		if (distance[S] > V) {
			printf ("YES\n");
			break;
		}
	}

	if (distance[S] <= V) {
		printf ("NO\n");
	}
}
