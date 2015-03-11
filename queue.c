/*************************************************************************
	> File Name: queue.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 19 Dec 2014 18:20:18 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct stu {
	char name[10];
	char id[10];
}stu;

typedef struct node{
	struct node* next;
	stu* student;
}node;

void createNode(node**);
void addNode(node**, node**, node*);
void display(node*);
void deleteNode(node**, node**);
void top(node*);
void retrive(node**);
void instruction();

int main() {
	instruction();	

	return 0;
}

void instruction() {
    char character;
	node* newNode = NULL;
	node* head = NULL;
	node* tail = NULL;

	printf("please input number:(a for add student, d for delete a student, p for print, q for quit): ");

	scanf("%c", &character);
	
	while ( character != 'q') {
		switch (character) {
			case 'a':
				createNode(&newNode);
				addNode(&tail, &head, newNode);
				break;
			case 'd':
				deleteNode(&head, &tail);
				break;
			case 'p':
				display(head);
				break;
			default:
				printf("Invalid choice.\n\n");
				break;
		}
		printf("please input number:(a for add student, d for delete a student, p for print, q for quit): ");
		scanf(" %c", &character);
	}
}

void createNode(node** newNode) {
	stu* student = (stu*) malloc (sizeof (stu));

	printf("please input the student's name and id: ");
	scanf("%s %s", student->name, student->id);
	
	*newNode = (node*) malloc (sizeof (node));
	(*newNode)->student = student;
	(*newNode)->next = NULL;
}

void addNode(node** tail, node** head, node* newNode) {
	if (*tail == NULL) {
		*head = *tail = newNode;
		return;
	}
	(*tail)->next = newNode;
	*tail = newNode;
}

void deleteNode(node** head, node** tail) {
	if (*head == NULL) {
		return;
	}
	node* deleteNode = *head;
	*head = (*head)->next;

	free(deleteNode->student);
	free(deleteNode);
	
	if (*head == NULL) {
		*tail = NULL;
	}
}

void display(node* currentNode) {
	while (currentNode != NULL) {
		printf("name: %s, id: %s\n", currentNode->student->name, currentNode->student->id);
		currentNode = currentNode->next;
	}
}
