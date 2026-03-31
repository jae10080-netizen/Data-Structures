#include <stdio.h>

int main(void)
{
	struct employee {
		char name[10];
		int year;
		int pay;
	};

	struct employee Lee = { "Ann",2022,5200 };

	return 0;
}