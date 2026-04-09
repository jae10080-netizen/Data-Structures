#include <stdio.h>
#include "deQue.h"

int main(void) {
	DQueueType* DQ1 = createDQueue();
	element data;

	printf("\n ***** µ¥Å© ¿¬»ê ***** \n");

	printf("\n front »ðÀÔ A>>");
	insertFront(DQ1, 'A');
	printDQ(DQ1);

	printf("\n front »ðÀÔ B>>");
	insertFront(DQ1, 'B');
	printDQ(DQ1);

	printf("\n rear  »ðÀÔ C>>");
	insertRear(DQ1, 'C');
	printDQ(DQ1);

	printf("\n front »èÁ¦  >>");
	data = deleteFront(DQ1);
	printDQ(DQ1);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ: %c", data);

	printf("\n rear  »èÁ¦  >>");
	data = deleteRear(DQ1);
	printDQ(DQ1);
	printf("\t\t»èÁ¦ µ¥ÀÌÅÍ: %c", data);

	printf("\n rear  »ðÀÔ D>>");
	insertRear(DQ1, 'D');
	printDQ(DQ1);

	printf("\n front »ðÀÔ E>>");
	insertFront(DQ1, 'E');
	printDQ(DQ1);

	printf("\n front »ðÀÔ F>>");
	insertFront(DQ1, 'F');
	printDQ(DQ1);

	printf("\n peek Front item: %c", peekFront(DQ1));
	printf("\n peek Rear item: %c \n", peekRear(DQ1));

	printf("\n");
	getchar();
	return 0;
}