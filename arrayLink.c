/*************************************************************************
	> File Name: arrayLink.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Sun 21 Dec 2014 13:35:44 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct stu {
	char name[MAX];
	char id[MAX];
}stu;

typedef struct linkNode {
	struct linkNode* next;
	stu* student;
}linkNode;

void xmalloc (size_t);
void hashFunction(linkNode***);
void instruction();
void createNode(linkNode** );
void insert(linkNode**);
int delete(linkNode**, const char*);
void printfList(linkNode**);


void instruction() {

	linkNode** headNode;
	char instruction = '\0';

	*headNode = (linkNode*) malloc (sizeof (linkNode*) * 10);
	memset(*headNode, 0, sizeof (linkNode*) * MAX);

	printf("please input the instructions (i for inserting, d for deleting, p for print list): ");
	scanf(" %c", &instruction);
	char id[10];

	while (instruction != 'q') {
		
		switch (instruction) {
			case 'i':
				hashFunction( &headNode );
				break;
			case 'd':
				printf("please input the id you want to find!\n");
				scanf("%s", id);
				delete(headNode, id);
				break;
			case 'p':
				printfList(headNode);
				break;
			default:
				printf("invalid input!\n");
				break;
		}

	printf("please input the instructions (i for inserting, d for deleting, p for print list): ");
		scanf(" %c", &instruction);
	}
}

void hashFunction(linkNode*** headNode) {
	int i;
	char x;
	int integer;

	for (i = strlen(newStudent->id)-1; i >= 0; i-- ) {
		if ( (newStudent->id)[i] >= '0' && (newStudent->id)[i] <= '9' ) {
			x = (newStudent->id)[i];
			break;
		}
	}

	integer = x - '0';

	insert( (*headNode) + integer );
}

void* xmalloc (size_t size) {
	void* ptr = malloc(size);

	if (ptr == NULL) {
		exit(1);
	}

	return ptr;
}

void createNode(linkNode** newNode, stu* newStudent) {
	(*newNode)->student = newStudent;
}

void insert(linkNode** firstNode, stu* newStudent) {
	linkNode* newNode = NULL;
	linkNode* currentNode = *firstNode;
	linkNode* previousNode = NULL;
	stu* newStudent = (stu*) xmalloc (sizeof (stu));
	
	printf("please input the name and id of the new student: ");
	scanf(" %s %s", newStudent->name, newStudent->id);

	*newNode = (linkNode*) xmalloc (sizeof (linkNode));
	createNode(&newNode, newStudent);
	
	while (currentNode != NULL && strcmp (currentNode->student->id, newNode->student->id) < 0) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	if (previousNode == NULL) {
		newNode->next = currentNode;
		*firstNode = newNode;
	} else {
		previousNode->next = newNode;
		newNode->next = currentNode;
	}
}

int delete(linkNode** firstNode, const char* id) {
	linkNode* currentNode = *firstNode;
	linkNode* previousNode = NULL;
	int isSuccess = 0;

	while (currentNode != NULL && strcmp(id, currentNode->student->id) > 0) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	while (previousNode == NULL && currentNode != NULL && strcmp(currentNode->student->id, id) == 0) {
		*firstNode = currentNode->next;
		free(currentNode->student);
		free(currentNode);
		currentNode = *firstNode;
		isSuccess = 1;
	}

	while (previousNode != NULL && currentNode != NULL && strcmp(currentNode->student->id, id) == 0) {
		previousNode->next = currentNode->next;
		free(currentNode->student);
		free(currentNode);
		currentNode = previousNode->next;		
		isSuccess = 1;
	}

	return isSuccess;
}


void printLink(linkNode** start) {
	int i; 
	linkNode* currentNode = NULL;

	for ( i = 0; i < MAX; i++ ) {
		printf("%d", i);
		currentNode = *(start+i);

		while (currentNode != NULL) {
			printf("----->(%s %s)", currentNode->student->name, currentNode->student->id);
		}
		printf("\n");
	}
}
