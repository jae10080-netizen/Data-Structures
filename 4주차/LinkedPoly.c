#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedPoly.h"

// 공백 다항식 리스트를 생성하는 연산
ListHead* createLinkedList(void) {
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}

// 다항식 리스트에 항을 추가하는 연산
void appendTerm(ListHead* L, float coef, int expo) {
	ListNode* newNode;
	ListNode* p;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;

	if (L->head == NULL) { // 다항식 리스트가 공백인 경우
		L->head = newNode;
		return;
	}
	else { // 다항식 리스트가 공백이 아닌 경우
		p = L->head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = newNode;
	}
}

// 두 다항식의 덧셈을 구하는 연산
void addPoly(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* pA = A->head;
	ListNode* pB = B->head;
	float sum;

	// 두 다항식에 노드가 있는 동안 반복
	while (pA && pB) {
		if (pA->expo == pB->expo) { // 지수가 같은 경우
			sum = pA->coef + pB->coef;
			if (sum != 0) appendTerm(C, sum, pA->expo);
			pA = pA->link;
			pB = pB->link;
		}
		else if (pA->expo > pB->expo) { // A의 지수가 큰 경우
			appendTerm(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		else { // B의 지수가 큰 경우
			appendTerm(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}

	// A에 남은 노드들을 C에 추가
	for (; pA != NULL; pA = pA->link)
		appendTerm(C, pA->coef, pA->expo);

	// B에 남은 노드들을 C에 추가
	for (; pB != NULL; pB = pB->link)
		appendTerm(C, pB->coef, pB->expo);
}

// 다항식 리스트를 출력하는 연산
void printPoly(ListHead* L) {
	ListNode* p = L->head;
	for (; p; p = p->link) {
		printf("%3.0fx^%d", p->coef, p->expo);
		if (p->link != NULL) printf(" +");
	}
	printf("\n");
}