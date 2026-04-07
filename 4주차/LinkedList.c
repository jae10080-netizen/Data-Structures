#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

//공백 연결 리스트를 생성하는 연산
ListHead* createLinkedList_h(void) {
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL; //공백 리스트이므로 NULL로 설정
	return L;
}
//연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(ListHead* L) {
	ListNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

//연결 리스트를 순서대로 출력하는 연산
void printList(ListHead* L) {
	ListNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

//첫 번째 노드로 삽입하는 연산
void insertFirstNode(ListHead* L, char* x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode)); //삽입할 새 노드 할당
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

//노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(ListHead* L, ListNode* pre, char* x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

//마지막 노드로 삽입하는 연산
void insertLastNode(ListHead* L, char* x) {
	ListNode* newNode;
	ListNode* temp;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	//현재 리스트가 공백이 아닌 경우
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}

//리스트에서 노드 p를 삭제하는 연산
void deleteNode(ListHead* L, ListNode* p) {
	ListNode* pre;
	if (L->head == NULL) return;
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL) return;
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

//리스트에서 x노드를 탐색하는 연산
ListNode* searchNode(ListHead* L, char* x) {
	ListNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

//리스트의 노드 순서를 역순으로 바꾸는 연산
void reverse(ListHead* L) {
	ListNode* p;
	ListNode* q;
	ListNode* r;

	p = L->head;
	q = NULL;
	r = NULL;

	//리스트의 첫 번째 노드부터 링크를 따라 다음 노드로 이동하면서 
	//노드간의 연결을 바꿈
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}