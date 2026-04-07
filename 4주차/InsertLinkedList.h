#pragma once
//단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} ListNode;

//리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	ListNode* head;
} ListHead;

ListHead* createLinkedList_h(void);
void freeLinkedList_h(ListHead* L);
void printList(ListHead* L);
void insertFirstNode(ListHead * L, char* x);
void insertMiddleNode(ListHead* L, ListNode* pre, char* x);
void insertLastNode(ListHead* L, char* h);