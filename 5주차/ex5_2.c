#include <stdio.h>
#include "stackL.h"

int main(void) {
	element item;
	top = NULL; // 처음 스택은 비어있으므로 top을 NULL로 초기화

	printf("\n** 연결 스택 연산 **\n");
	printStack();

	push(1); printStack(); // 1 삽입
	push(2); printStack(); // 2 삽입
	push(3); printStack(); // 3 삽입

	item = peek(); printStack(); // 현재 top의 원소 출력
	printf("peek => %d", item);

	item = pop(); printStack(); // 삭제
	printf("\t pop => %d", item);

	item = pop(); printStack(); // 삭제
	printf("\t pop => %d", item);

	item = pop(); printStack(); // 삭제
	printf("\t pop => %d\n", item);

	getchar();
	return 0;
}