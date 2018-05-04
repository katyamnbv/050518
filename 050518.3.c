#include <stdio.h>
#include <stdlib.h>


int main() {
	FILE *fp = fopen("one.txt", "r"); //��������� ���� � �������
	FILE *fp1 = fopen("copy.txt", "w"); //���� �� ����� ���������� �������
	FILE *fp2 = fopen("copy2.txt", "w"); //��������������� ����

	//��������
	if (fp == NULL) {
		fprintf(stderr, "���������� ������� ����\n");
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
