#include<stdio.h>

int main(void)
{
	int count = 0;
	char string[100];


	printf("문자열을 입력하세요:");
	scanf_s("%s",string,sizeof(string));

	for (int i = 0; i < sizeof(string); i++) {
		if (string[i] == '\0') {
			break;
		}
		else {
			count++;
		}
	}

	printf("입력된 문자열은\n\"%s\"\n입니다.\n\n", string);
	printf("입력된 문자열의 길이 = %d", count);

}