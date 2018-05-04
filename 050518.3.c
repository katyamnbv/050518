#include <stdio.h>
#include <stdlib.h>


int main() {
	FILE *fp = fopen("one.txt", "r"); //Начальный файл с текстом
	FILE *fp1 = fopen("copy.txt", "w"); //Файл со всеми заглавными буквами
	FILE *fp2 = fopen("copy2.txt", "w"); //Вспомогательный файл

	//Проверка
	if (fp == NULL) {
		fprintf(stderr, "Невозможно открыть файл\n");
		return 0;
	}

	char c;
	while ((c = fgetc(fp)) != EOF) {
		putc(c, fp2);
		if (c >= 'a' && c <= 'z')
			putc(c - 'a' + 'A', fp1);
		else
			putc(c, fp1);
	}

	fclose(fp);
	fclose(fp1);
	fclose(fp2);

	return 0;
}
