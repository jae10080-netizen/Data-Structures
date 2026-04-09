#include <stdio.h>
#include <stdlib.h>
#include "lQueue.h"

// 공백 연결 큐를 생성하는 연산
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isLQEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;

	if (LQ->front == NULL) { // 큐가 비어있을 때
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else { // 큐가 비어있지 않을 때 (기존 꼬리 뒤에 연결)
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// 연결 큐의 front에서 원소를 삭제하고 반환하는 연산
element deLQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	element item;
	if (isLQEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL) // 삭제 후 큐가 텅 비게 된 경우
			LQ->rear = NULL;
		free(old); // 메모리 반환(삭제)
		return item;
	}
}

// 연결 큐의 가장 앞에 있는 원소를 검색하는 연산
element peekLQ(LQueueType* LQ) {
	if (isLQEmpty(LQ)) return 0;
	else return LQ->front->data;
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) { // temp가 NULL이 될 때까지 (끝까지) 반복
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}