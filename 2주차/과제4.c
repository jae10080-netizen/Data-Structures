#include<stdio.h>

int fact(int n);

int main(void)
{
	int num = 0;
	int result = 0;
	printf("정수를 입력하세요: ");
	scanf_s("%d", &num);

	result = fact(num);

	printf("%d의 팩토리얼 값은 %d입니다.\n", num, result);
	
	return 0;
}

int fact(int n) {
	printf("fact(%d) 함수 호출!\n", n);
	if (n <= 1) {
		printf("fact(%d) 값 1 반환!\n", n);
		return(1);
	}
	else {
		int res = (n * fact(n - 1));
		printf("fact(%d) 값 %d 반환!\n", n,res);

		return res;
	}
}