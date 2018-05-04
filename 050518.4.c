#include <stdio.h>
#include <string.h>

int main() {
	char file1_name[] = "one.txt";
	char file2_name[] = "two.txt";

	FILE* file1 = fopen(file1_name, "r");
	FILE* file2 = fopen(file2_name, "r");

    //Проверка
	if (file1 == NULL || file2 == NULL) {
		return 0;
	}

	char buffer[256];

	while (!feof(file1) || !feof(file2)) {
		fgets(buffer, sizeof(buffer), file1);
		int size = strlen(buffer);
		if (size != 0) {
			size--;
		}
		fgets(buffer + size, sizeof(buffer) - size, file2);
		printf("%s", buffer);
		memset(buffer, 0, sizeof(buffer));
	}

	return 0;
}
