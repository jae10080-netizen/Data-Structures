#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

// 원형 큐를 생성하는 연산 (35페이지)
QueueType* createCQueue() {
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0; // front 초깃값 설정 (원형 큐는 0부터 시작!)
	cQ->rear = 0;  // rear 초깃값 설정
	return cQ;
}

// 원형 큐가 공백 상태인지 검사하는 연산 (35페이지)
int isCQueueEmpty(QueueType* cQ) {
	if (cQ->front == cQ->rear) {
		printf(" Circular Queue is empty! ");
		return 1;
	}
	else return 0;
}

// 원형 큐가 포화 상태인지 검사하는 연산 (35페이지)
int isCQueueFull(QueueType* cQ) {
	// rear를 한 칸 앞으로 밀어봤을 때 front와 겹치면 꽉 찬 것!
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {
		printf(" Circular Queue is full! ");
		return 1;
	}
	else return 0;
}

// 원형 큐의 rear에 원소를 삽입하는 연산 (36페이지)
void enCQueue(QueueType* cQ, element item) {
	if (isCQueueFull(cQ))
		return;
	else {
		// 원형 큐의 핵심! 끝에 도달하면 다시 0번 인덱스로 돌아감
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

// 원형 큐의 front에서 원소를 삭제하고 반환하는 연산 (36페이지)
element deCQueue(QueueType* cQ) {
	if (isCQueueEmpty(cQ)) return 0;
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

// 원형 큐의 가장 앞에 있는 원소를 검색하는 연산 (36페이지)
element peekCQ(QueueType* cQ) {
	if (isCQueueEmpty(cQ))
		exit(1);
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

// 원형 큐의 원소를 출력하는 연산 (37페이지)
void printCQ(QueueType* cQ) {
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;
	printf(" Circular Queue: [");

	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf(" ]");
}