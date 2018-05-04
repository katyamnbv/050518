#include <stdio.h>
#include <string.h>

main () {
	int m, n = 0;

	char file_name[] = "one.txt";

	scanf("%d %d", &m, &n);

	if (n < m || n > 255 || m > 255) {
		return 0;
	}

	FILE* file = fopen(file_name,"r");

	if (file == NULL){
		return 0;
	}

	char buffer[255];

	while (!feof(file)) {
		fgets(buffer, sizeof(buffer), file);
		int size = strlen(buffer);
		buffer[size - 1] = '\0';
		if (n < size) {
			buffer[n + 1] = '\0';
		}

		printf("%s\n", buffer + m);
		memset(buffer, 0, sizeof(buffer));
	}

}
