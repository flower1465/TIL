#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char* argv[])
{
	FILE* read_fp, * write_fp;
	int c;
	if (argc <= 2) {
		printf("argument error!!\nThis program requires 3arguments!!\n");
			exit(-1);
	}
	read_fp = fopen(argv[1], "r");

	if (read_fp == NULL) {
		printf("%s file open error!!!\n", argv[1]);
		exit(-1);
	}
	else {
		if ((write_fp = fopen(argv[2], "w")) != NULL) {
			while ((c = fgetc(read_fp)) != EOF) {
				fputc(c, write_fp);
			}
			fclose(read_fp);
			fclose(write_fp);
			printf("%s 파일에 저장 완료.\n", argv[2]);
		}
		else {
			printf("%s file open error!!!\n", argv[2]);
			exit(-1);
		}
	}
	return 0;
}