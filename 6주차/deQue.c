#include <stdio.h>
#include <stdlib.h>
#include "deQue.h"

// 공백 데크를 생성하는 연산
DQueueType* createDQueue() {
	DQueueType* DQ = (DQueueType*)malloc(sizeof(DQueueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// 데크가 공백 상태인지 검사하는 연산
int isDQEmpty(DQueueType* DQ) {
	if (DQ->front == NULL) return 1;
	else return 0;
}

// 데크의 front(앞) 앞으로 원소를 삽입하는 연산
void insertFront(DQueueType* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDQEmpty(DQ)) { // 비어있을 때
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else { // 비어있지 않을 때
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;
	}
}

// 데크의 rear(뒤) 뒤로 원소를 삽입하는 연산
void insertRear(DQueueType* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDQEmpty(DQ)) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

// 데크의 front(앞) 원소를 삭제하는 연산
element deleteFront(DQueueType* DQ) {
	DQNode* old = DQ->front;
	element item;
	if (isDQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n");
		return 0;
	}
	else {
		item = old->data;
		if (DQ->front->rlink == NULL) { // 노드가 1개 남았을 때 삭제하는 경우
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}

// 데크의 rear(뒤) 원소를 삭제하는 연산
element deleteRear(DQueueType* DQ) {
	DQNode* old = DQ->rear;
	element item;
	if (isDQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n");
		return 0;
	}
	else {
		item = old->data;
		if (DQ->rear->llink == NULL) { // 노드가 1개 남았을 때 삭제하는 경우
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

// 데크의 앞/뒤 원소 검색 연산
element peekFront(DQueueType* DQ) {
	if (isDQEmpty(DQ)) return 0;
	else return DQ->front->data;
}
element peekRear(DQueueType* DQ) {
	if (isDQEmpty(DQ)) return 0;
	else return DQ->rear->data;
}

// 데크의 원소를 출력하는 연산
void printDQ(DQueueType* DQ) {
	DQNode* temp = DQ->front;
	printf(" DeQue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ] ");
}