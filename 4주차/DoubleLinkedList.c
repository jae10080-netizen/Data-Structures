#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"

// 공백 이중 연결 리스트 생성
ListHead* createLinkedList_h(void) {
	ListHead* DL = (ListHead*)malloc(sizeof(ListHead));
	DL->head = NULL;
	return DL;
}

// 리스트 출력
void printList(ListHead* DL) {
	ListNode* p;
	printf("DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// 노드 삽입 (pre 노드 뒤에 삽입)
void insertNode(ListHead* DL, ListNode* pre, char* x) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);

	if (DL->head == NULL) { // 리스트가 비어있을 때
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else if (pre == NULL) { // 맨 앞에 삽입할 때
		newNode->rlink = DL->head;
		newNode->llink = NULL;
		DL->head->llink = newNode;
		DL->head = newNode;
	}
	else { // 중간이나 마지막에 삽입할 때
		newNode->rlink = pre->rlink;
		newNode->llink = pre;
		if (pre->rlink != NULL) pre->rlink->llink = newNode;
		pre->rlink = newNode;
	}
}

// 노드 삭제
void deleteNode(ListHead* DL, ListNode* old) {
	if (DL->head == NULL || old == NULL) return;

	if (old->llink == NULL) { // 삭제할 노드가 첫 번째 노드인 경우
		DL->head = old->rlink;
		if (DL->head != NULL) DL->head->llink = NULL;
	}
	else { // 중간이나 마지막 노드인 경우
		old->llink->rlink = old->rlink;
		if (old->rlink != NULL) old->rlink->llink = old->llink;
	}
	free(old);
}

// 노드 탐색
ListNode* searchNode(ListHead* DL, char* x) {
	ListNode* temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		temp = temp->rlink;
	}
	return temp;
}