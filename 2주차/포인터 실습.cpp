#include<stdio.h>

int main(void)
{
	int val = 15;
	int* pval = NULL;

	pval = &val;

	*(pval) = 16;

	return 0;
}