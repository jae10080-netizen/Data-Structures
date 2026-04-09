#pragma once

typedef char element; // 데크 원소의 자료형을 char로 정의

// 이중 연결 리스트의 노드 구조체
typedef struct DQNode {
	element data;
	struct DQNode* llink; // 왼쪽(앞) 노드를 가리키는 포인터
	struct DQNode* rlink; // 오른쪽(뒤) 노드를 가리키는 포인터
} DQNode;

// 데크의 상태를 관리하는 구조체
typedef struct {
	DQNode* front, * rear;
} DQueueType;

DQueueType* createDQueue();
int isDQEmpty(DQueueType* DQ);
void insertFront(DQueueType* DQ, element item);
void insertRear(DQueueType* DQ, element item);
element deleteFront(DQueueType* DQ);
element deleteRear(DQueueType* DQ);
element peekFront(DQueueType* DQ);
element peekRear(DQueueType* DQ);
void printDQ(DQueueType* DQ);
