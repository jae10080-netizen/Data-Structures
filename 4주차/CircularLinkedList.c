#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"

// 공백 원형 연결 리스트 생성
ListHead* createLinkedList_h(void) {
    ListHead* CL;
    CL = (ListHead*)malloc(sizeof(ListHead));
    CL->head = NULL;
    return CL;
}

// 원형 연결 리스트 출력
void printList(ListHead* CL) {
    ListNode* p;
    printf("CL = (");
    p = CL->head;
    if (p == NULL) {
        printf(") \n");
        return;
    }
    do {
        printf("%s", p->data);
        p = p->link;
        if (p != CL->head) printf(", ");
    } while (p != CL->head);
    printf(") \n");
}

// 첫 번째 노드로 삽입
void insertFirstNode(ListHead* CL, char* x) {
    ListNode* newNode, * temp;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    strcpy(newNode->data, x);

    if (CL->head == NULL) { // 리스트가 비어있는 경우
        CL->head = newNode;
        newNode->link = newNode;
    }
    else { // 리스트가 비어있지 않은 경우
        temp = CL->head;
        while (temp->link != CL->head) {
            temp = temp->link;
        }
        newNode->link = CL->head;
        temp->link = newNode;
        CL->head = newNode;
    }
}

// 중간 노드로 삽입
void insertMiddleNode(ListHead* CL, ListNode* pre, char* x) {
    ListNode* newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    strcpy(newNode->data, x);

    if (CL->head == NULL) { // 리스트가 비어있는 경우
        CL->head = newNode;
        newNode->link = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

// 마지막 노드로 삽입
void insertLastNode(ListHead* CL, char* x) {
    ListNode* newNode, * temp;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    strcpy(newNode->data, x);

    if (CL->head == NULL) { // 리스트가 비어있는 경우
        CL->head = newNode;
        newNode->link = newNode;
    }
    else {
        temp = CL->head;
        while (temp->link != CL->head) {
            temp = temp->link;
        }
        newNode->link = CL->head;
        temp->link = newNode;
    }
}

// 노드 삭제
void deleteNode(ListHead* CL, ListNode* old) {
    ListNode* pre;
    if (CL->head == NULL) return;
    if (CL->head->link == CL->head) { // 리스트에 노드가 하나만 있는 경우
        free(CL->head);
        CL->head = NULL;
        return;
    }
    else if (old == NULL) return;
    else {
        pre = CL->head;
        while (pre->link != old) {
            pre = pre->link;
        }
        pre->link = old->link;
        if (old == CL->head) CL->head = old->link;
        free(old);
    }
}

// 노드 탐색
ListNode* searchNode(ListHead* CL, char* x) {
    ListNode* temp;
    temp = CL->head;
    if (temp == NULL) return NULL;

    do {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;
    } while (temp != CL->head);

    return NULL;
}