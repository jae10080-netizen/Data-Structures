#include <stdio.h>

int main(void) {
	char student[2][3][20] = {{ "Hong Gil Dong","Computer Electronic","202100101" },
	{ "Hong Gil Soon", "Computer Science", "202100201" }
};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				printf("학생 %d의 이름 : ", i + 1);
			}
			else if (j == 1) {
				printf("학생 %d의 학과 : ", i + 1);
			}			
			else {
				printf("학생 %d의 학번 : ", i + 1);
			}

			for (int k = 0; k < 20; k++) {
				if (student[i][j][k] == '\0') break;
				printf("%c", student[i][j][k]);
			}
			printf("\n");
		}

		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		printf("학생 %d\n", i + 1);
		for (int j = 0; j < 3; j++) {

			printf("\t");
			for (int k = 0; k < 20; k++) {
				printf("%c", student[i][j][k]);
			}
			printf("\n");
		}

		printf("\n");
	}

}