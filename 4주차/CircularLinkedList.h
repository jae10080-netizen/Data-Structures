#pragma once

// 원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} ListNode;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	ListNode* head;
} ListHead;

ListHead* createLinkedList_h(void);
void printList(ListHead* CL);
void insertFirstNode(ListHead* CL, char* x);
void insertMiddleNode(ListHead* CL, ListNode* pre, char* x);
void deleteNode(ListHead* CL, ListNode* old);
ListNode* searchNode(ListHead* CL, char* x);

