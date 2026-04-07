#pragma once

// 이중 연결 리스트의 노드 구조 설계
typedef struct ListNode {
	struct ListNode* llink; // 왼쪽(이전) 노드 포인터
	char data[4];
	struct ListNode* rlink; // 오른쪽(다음) 노드 포인터
} ListNode;

typedef struct {
	ListNode* head;
} ListHead;

ListHead* createLinkedList_h(void);
void printList(ListHead* DL);
void insertNode(ListHead* DL, ListNode* pre, char* x);
void deleteNode(ListHead* DL, ListNode* old);
ListNode* searchNode(ListHead* DL, char* x);
