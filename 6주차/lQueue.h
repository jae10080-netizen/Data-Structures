#pragma once

typedef char element; // 큐 원소의 자료형을 char로 정의

// 큐의 노드 구조체 (데이터와 다음 노드를 가리키는 포인터)
typedef struct QNode {
	element data;
	struct QNode* link;
} QNode;

// 연결 큐의 상태를 관리하는 구조체 (front와 rear 포인터)
typedef struct {
	QNode* front, * rear;
} LQueueType;

LQueueType* createLinkedQueue();
int isLQEmpty(LQueueType* LQ);
void enLQueue(LQueueType* LQ, element item);
element deLQueue(LQueueType* LQ);
element peekLQ(LQueueType* LQ);
void printLQ(LQueueType* LQ);