#include<stdio.h>

int main(void)
{
	char* ptr[4] = { "Korea","Seoul","Mapo","152¹øÁö 2/3" };


	for (int i = 0; i < 4; i++) {
		printf("%s \n", ptr[i]);
	}

	printf("\n\n");
	
	ptr[2] = "Jongno";

	for (int i = 0; i < 4; i++) {
		printf("%s \n", ptr[i]);
	}
}