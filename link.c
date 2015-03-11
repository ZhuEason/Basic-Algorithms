/*************************************************************************
	> File Name: link.c
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Sat 20 Dec 2014 20:40:22 HKT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct stu{
	char name[MAX];
	char id[MAX];
}stu;

typedef struct linkNode{
	stu* student;
	struct linkNode* next;
}linkNode;

void createNode(linkNode**);
void insert(linkNode**, linkNode*);
int delete(linkNode**, const char* );
void printLink(linkNode*);
void instruction();
void* xmalloc(size_t);

int main() {
	instruction();

	return 0;
}

void* xmalloc(size_t size) {
	void* ptr = malloc (size);
	if (ptr == NULL) {
		exit(1);
	}
	
	return ptr;
}

void instruction() {
    char character;
	linkNode* newNode = NULL;
	linkNode* firstNode = NULL;
	char id[10];

	printf("please input number:(i for add student, d for delete a student, p for print, q for quit): ");

	scanf("%c", &character);
	
	while ( character != 'q') {
		switch (character) {
			case 'i':
				createNode(&newNode);
				insert(&firstNode, newNode);
				break;
			case 'd':
				printf("please input the students you are going to delete: ");
				scanf("%s", id);
				if ( delete(&firstNode, id) ) {
					printf("delete successfully!\n");
				} else {
					printf("not found such a student!\n");
				}
				break;
			case 'p':
				printLink(firstNode);
				break;
			default:
				printf("Invalid choice.\n\n");
				break;
		}
		printf("please input number:(a for add student, d for delete a student, p for print, q for quit): ");
		scanf(" %c", &character);
	}
}

void createNode(linkNode ** newNode) {
	stu* student = (stu*) xmalloc (sizeof (stu));
	printf("please input the student's name and id: ");
	scanf("%s %s", student->name, student->id);
	*newNode = (linkNode*) xmalloc (sizeof (newNode));
	(*newNode)->student = student;
	(*newNode)->next = NULL;
}

void insert(linkNode** firstNode, linkNode* newNode) {
	linkNode* currentNode = *firstNode;
	linkNode* previousNode = NULL;

	while (currentNode != NULL && strcmp(newNode->student->id, currentNode->student->id) > 0 ){
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	if (previousNode == NULL) {
		*firstNode = newNode;
		newNode->next = currentNode;
	} else {
		previousNode->next = newNode;
		newNode->next = currentNode;
	}
	
	//the second way to implement insert
	//
	//linkNode** currentNode = firstNode;
	//
	//while (*currentNode != NULL && strcmp(newNode->student->id, (*currentNode)->student->id) > 0) {
	//		currentNode = &(*currentNode)->next;
	//}
	//
	//*currentNode = newNode;
	//newNode->next = (*currentNode)->next;
} 

int delete (linkNode** firstNode, const char* id) {
	linkNode* currentNode = *firstNode;
	linkNode* previousNode = NULL;
//	linkNode* tempNode = NULL;
	int isSuccess = 0;

	while ( currentNode != NULL && strcmp(id, currentNode->student->id) > 0 ) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	while ( previousNode == NULL && currentNode != NULL && strcmp(id, currentNode->student->id) == 0) {
		free(currentNode->student);
		free(currentNode);
		*firstNode = (*firstNode)->next;
		currentNode = *firstNode;
		isSuccess = 1;
	}
	
	while ( previousNode != NULL && currentNode != NULL && strcmp(currentNode->student->id, id) == 0 ) {
		previousNode->next = currentNode->next;	
		free(currentNode->student);
		free(currentNode);
		currentNode = previousNode->next;
		isSuccess = 1;
	}

	return isSuccess;
}


void printLink(linkNode* currentNode) {
	while (currentNode != NULL) {
		printf("name: %s id: %s\n", currentNode->student->name, currentNode->student->id );
		currentNode = currentNode->next;
	}
}


